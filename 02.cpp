#include <iostream>

int main() {
  int a = 3;
  int &another_a = a; // reference

  another_a = 5;
  std::cout << "a         : " << a << std::endl;
  std::cout << "another_a : " << a << std::endl;

  // reference와 pointer의 차이
  // 1. 정의시에 명시해야 함
  // 2. 변경할 수 없음
  // 3. 메모리 상에서 존재하지 않음
  // 4. 이중참조는 없음
  // 5. 상수에 대한 참조는 불가
  // 6. 참조자의 배열, 참조자 포인터는 없음

  int x;
  int &y = x;
  int &z = y;

  x = 1;
  std::cout << "x : " << x << ", y : " << y << ", z : " << z << std::endl;
  y = 2;
  std::cout << "x : " << x << ", y : " << y << ", z : " << z << std::endl;
  z = 3;
  std::cout << "x : " << x << ", y : " << y << ", z : " << z << std::endl;

  return 0;
}