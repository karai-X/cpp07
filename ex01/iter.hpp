#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef> // for size_t

// 汎用的な iter テンプレート。
// - T は配列の要素型（配列が const の場合は const を含む型になる）
// - Func は配列要素に作用する関数や関数オブジェクトの型
template <typename T, typename Func>
void iter(T *array, const std::size_t length, Func f) {
  for (std::size_t i = 0; i < length; ++i) {
    f(array[i]);
  }
}

#endif // ITER_HPP
