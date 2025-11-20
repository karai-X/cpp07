#include "iter.hpp"
#include <iostream>
#include <string>

// 汎用的に使える関数テンプレート（引数は const reference）
template <typename U> void printConst(const U &x) {
  std::cout << x << std::endl;
}

// 非 const 参照で要素を変更する関数
void increment(int &x) { ++x; }

// char を大文字にする（非 const 参照）
void toUpper(char &c) {
  if (c >= 'a' && c <= 'z')
    c = c - 'a' + 'A';
}

int main() {
  // --- int 配列（非 const）: increment が使える ---
  int arr[] = {1, 2, 3, 4};
  std::size_t n = sizeof(arr) / sizeof(arr[0]);

  std::cout << "original ints:" << std::endl;
  iter(arr, n, &printConst<int>); // 関数テンプレートを明示的に指定して渡せる
  iter(arr, n, increment); // 非 const 関数で値を変更
  std::cout << "after increment:" << std::endl;
  iter(arr, n, printConst<int>);

  std::cout << "----" << std::endl;

  // --- const std::string 配列（const）: 変更不可なので print のみ ---
  const std::string names[] = {"Alice", "Bob", "Carol"};
  std::size_t m = sizeof(names) / sizeof(names[0]);

  std::cout << "names (const array):" << std::endl;
  iter(names, m, &printConst<std::string>);

  std::cout << "----" << std::endl;

  // --- char 配列（非 const）: toUpper で変更 ---
  char letters[] = {'a', 'b', 'c', 'x', 'y', 'z'};
  std::size_t l = sizeof(letters) / sizeof(letters[0]);

  std::cout << "letters original:" << std::endl;
  iter(letters, l, &printConst<char>);
  iter(letters, l, toUpper);
  std::cout << "letters after toUpper:" << std::endl;
  iter(letters, l, &printConst<char>);

  std::cout << "----" << std::endl;

  // --- ラムダも使える（ここでは const 参照で表示） ---
  double vals[] = {0.1, 1.23, 4.56};
  std::size_t p = sizeof(vals) / sizeof(vals[0]);
  iter(vals, p,
       [](const double &d) { std::cout << "val: " << d << std::endl; });

  return 0;
}
