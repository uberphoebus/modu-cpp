#include <iostream>

class Marine {
private:
  int hp;
  int coord_x, coord_y;
  bool is_dead;
  const int default_damamge;

public:
  Marine();
  Marine(int x, int y);
  Marine(int x, int y, int default_damamge);

  void move(int x, int y);
  int attack();
  void be_attacked(int damage_earn);
  void show_status();
};

// initializer list : simultaneously construct + init
Marine::Marine()
    : hp(50), coord_x(0), coord_y(0), default_damamge(5), is_dead(false) {}

Marine::Marine(int x, int y)
    : hp(50), coord_x(x), coord_y(y), default_damamge(5), is_dead(false) {}

Marine::Marine(int x, int y, int default_damamge)
    : hp(50), coord_x(x), coord_y(y), default_damamge(default_damamge),
      is_dead(false) {}

void Marine::move(int x, int y) {
  coord_x = x;
  coord_y = y;
}

int Marine::attack() { return default_damamge; }

void Marine::be_attacked(int damage_earn) {
  hp -= damage_earn;
  if (hp <= 0) {
    is_dead = true;
  }
}

void Marine::show_status() {
  std::cout << "[marine] (" << coord_x << ", " << coord_y << ") | hp " << hp
            << std::endl;
}

int main() {
  Marine marine1(2, 3, 10);
  Marine marine2(3, 5, 10);

  marine1.show_status();
  marine2.show_status();

  std::cout << "marine1 attakcs marine2" << std::endl;
  marine2.be_attacked(marine1.attack());

  marine1.show_status();
  marine2.show_status();
}