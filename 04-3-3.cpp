#include <iostream>
#include <string.h>

class PhotonCannon {
private:
  int hp, shield;
  int coord_x, coord_y;
  int damage;
  char *name;

public:
  PhotonCannon(int x, int y);
  PhotonCannon(int x, int y, const char *cannon_name);
  PhotonCannon(const PhotonCannon &pc);
  ~PhotonCannon();

  void show_status();
};

PhotonCannon::PhotonCannon(int x, int y) {
  std::cout << "[call] constructor" << std::endl;
  hp = shield = 100;
  coord_x = x;
  coord_y = y;
  damage = 20;
  name = NULL;
}

PhotonCannon::PhotonCannon(const PhotonCannon &pc) {
  std::cout << "[call] copy constructor" << std::endl;
  hp = pc.hp;
  shield = pc.shield;
  coord_x = pc.coord_x;
  coord_y = pc.coord_y;
  damage = pc.damage;

  name = new char[strlen(pc.name) + 1];
  strcpy(name, pc.name);
}

PhotonCannon::PhotonCannon(int x, int y, const char *cannon_name) {
  std::cout << "[call] constructor" << std::endl;
  hp = shield = 100;
  coord_x = x;
  coord_y = y;
  damage = 20;

  // default copy constructor는 단순 값 대입인 shallow copy
  // 메모리를 새로 할당해서 deep copy를 해야,
  // 복사된 대상이 delete되고나서도 에러가 안생김
  name = new char[strlen(cannon_name) + 1];
  strcpy(name, cannon_name);
}

PhotonCannon::~PhotonCannon() {
  if (name) {
    delete[] name;
  }
}

void PhotonCannon::show_status() {
  std::cout << "[PhotonCannon] (" << coord_x << ", " << coord_y
            << "), hp : " << hp << std::endl;
}

int main() {
  PhotonCannon pc1(3, 3, "Cannon"); // constructor
  PhotonCannon pc2(pc1);            // copy
  PhotonCannon pc3 = pc2;           // copy

  pc1.show_status();
  pc2.show_status();
}