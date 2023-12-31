#include <iostream>
#include <string.h>

class Marine {
private:
  int hp;
  int coord_x, coord_y;
  int damage;
  bool is_dead;
  char *name;

public:
  Marine(); // default constructor
  Marine(int x, int y);
  Marine(int x, int y, const char *marine_name);

  void move(int x, int y);
  int attack();
  void be_attacked(int damage_earn);
  void show_status();
};

Marine::Marine() {
  hp = 50;
  coord_x = coord_y = 0;
  damage = 5;
  is_dead = false;
  name = NULL;
}

Marine::Marine(int x, int y) {
  hp = 50;
  coord_x = x;
  coord_y = y;
  damage = 5;
  is_dead = false;
  name = NULL;
}

Marine::Marine(int x, int y, const char *marine_name) {
  name = new char[strlen(marine_name) + 1]; // name not deleted
  strcpy(name, marine_name);

  hp = 50;
  coord_x = x;
  coord_y = y;
  damage = 5;
  is_dead = false;
}

void Marine::move(int x, int y) {
  coord_x = x;
  coord_y = y;
}

int Marine::attack() { return damage; }

void Marine::be_attacked(int damage_earn) {
  hp -= damage_earn;
  if (hp <= 0) {
    is_dead = true;
  }
}
void Marine::show_status() {
  std::cout << " [Marine] " << name << " Location : ( " << coord_x << " , "
            << coord_y << " ) "
            << "| HP : " << hp << std::endl;
}

int main() {
  // array of marines
  Marine marines[100];
  marines[0] = Marine(2, 3, "marine1");
  marines[1] = Marine(3, 5, "marine2");

  marines[0].show_status();
  marines[1].show_status();
  std::cout << std::endl << "[marines] marine1 attacks marine2" << std::endl;
  marines[0].be_attacked(marines[1].attack());
  marines[0].show_status();
  marines[1].show_status();

  // array of pointer : new, delete
  Marine *marines_p1[100];
  marines_p1[0] = new Marine(2, 3, "marine_p1 1");
  marines_p1[1] = new Marine(3, 5, "marine_p1 2");

  marines_p1[0]->show_status();
  marines_p1[1]->show_status();
  std::cout << std::endl << "[marines_p1] marine1 attacks marine2" << std::endl;
  marines_p1[0]->be_attacked(marines_p1[1]->attack());
  marines_p1[0]->show_status();
  marines_p1[1]->show_status();

  delete marines_p1[0];
  delete marines_p1[1];

  // new, delete array
  Marine *marines_p2 = new Marine[100];
  marines_p2[0] = Marine(2, 3, "marine_p2 1");
  marines_p2[1] = Marine(3, 5, "marine_p2 2");

  marines_p2[0].show_status();
  marines_p2[1].show_status();
  std::cout << std::endl << "[marines_p2] marine1 attacks marine2" << std::endl;
  marines_p2[0].be_attacked(marines_p2[1].attack());
  marines_p2[0].show_status();
  marines_p2[1].show_status();
  delete[] marines_p2;
}