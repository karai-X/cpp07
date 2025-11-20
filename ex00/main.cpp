#include "whatever.hpp"
#include <iostream>

int main() {
  int a = 2;
  int b = 3;

  swap(a, b);
  std::cout << "a = " << a << ", b = " << b << std::endl;
  std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
  std::cout << "max(a, b) = " << ::max(a, b) << std::endl;

  std::string c = "str1";
  std::string d = "str2";
  swap(c, d);
  std::cout << "c = " << c << ", d = " << d << std::endl;
  std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
  std::cout << "max(c, d) = " << ::max(c, d) << std::endl;

  float e = 2.0;
  float f = 3.5;

  swap(e, f);
  std::cout << "e = " << e << ", f = " << f << std::endl;
  std::cout << "min(e, f) = " << ::min(e, f) << std::endl;
  std::cout << "max(e, f) = " << ::max(e, f) << std::endl;

  return 0;
}
