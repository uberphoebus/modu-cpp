#include <iostream>

class Marine {
private:
  // static member var : shares with class instance
  static int total_marine_num;
  const static int i = 0;

  int hp;
  int coord_x, coord_y;
  bool is_dead;
  const int default_damamge;

public:
  Marine();
  Marine(int x, int y);
  Marine(int x, int y, int default_damamge);

  void move(int x, int y);
  int attack() const; // const function : not changing other var
  Marine &be_attacked(int damage_earn);
  void show_status();
  static void show_total_marine();
  ~Marine() { total_marine_num--; }
};

int Marine::total_marine_num = 0;

Marine::Marine()
    : hp(50), coord_x(0), coord_y(0), default_damamge(5), is_dead(false) {
  total_marine_num++;
}

Marine::Marine(int x, int y)
    : hp(50), coord_x(x), coord_y(y), default_damamge(5), is_dead(false) {
  total_marine_num++;
}

Marine::Marine(int x, int y, int default_damamge)
    : hp(50), coord_x(x), coord_y(y), default_damamge(default_damamge),
      is_dead(false) {
  total_marine_num++;
}

void Marine::move(int x, int y) {
  coord_x = x;
  coord_y = y;
}

int Marine::attack() const { return default_damamge; }

// reference return function
Marine &Marine::be_attacked(int damage_earn) {
  hp -= damage_earn; // not this->hp
  if (hp <= 0) {
    is_dead = true;
  }
  return *this; // points object itself
}

void Marine::show_status() {
  std::cout << "[marine] (" << coord_x << ", " << coord_y << ") | hp " << hp
            << " | total marines " << total_marine_num << std::endl;
}

void Marine::show_total_marine() {
  std::cout << "total marine num : " << total_marine_num << std::endl;
}

void create_marine() {
  Marine marine3(10, 10, 4);
  marine3.show_status();
}

int main() {
  Marine marine1(2, 3, 5);
  marine1.show_status(); // 1

  Marine marine2(3, 5, 10);
  marine2.show_status(); // 2

  create_marine(); // local var(2 -> 3 -> 2)

  std::cout << "marine1 attakcs marine2" << std::endl;
  marine2.be_attacked(marine1.attack()).be_attacked(marine1.attack());

  marine1.show_status(); // 2
  marine2.show_status(); // 2
}