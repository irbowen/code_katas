#include <algorithm>
#include <iostream>

template <typename T>
void mergeSort(std::vector<T> v) {
  mergeSort_1(v, 0, v.size()));
}

template <typename T>
void mergeSort_1(std::vector<T>& v, int l, int r) {
  if (l < r) {
    auto m = (r+1) / 2;
    mergeSort_1(v, l, m);
    mergeSort_1(v, m+1, r);
    merge(v, l, m, r);
  }
}

template <typename T>
void merge_1(std::vector<T> l, std::vector<T> r) {

}
