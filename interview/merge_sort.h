#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <functional>
#include <thread>

void fast_small_sort(std::vector<double>& v) {
  bool swaps = true;
  while (swaps) {
    swaps = false;
    for (size_t j = 0; j < v.size()-1; j++) {
      if (v.at(j) < v.at(j+1)) {
        std::swap(v.at(j), v.at(j+1));
        swaps = true;
      }
    }
  }
}

//template <typename T>
//void mergeSort_1(std::vector<T>& v, int l, int r) {
void mergeSort_1(std::vector<double>& v, int l, int r) {
  if (r-l > 1) {
    int m = (r + l) / 2;
    mergeSort_1(v, l, m);
    mergeSort_1(v, m, r);
    inplace_merge(v.begin()+l, v.begin()+m, v.begin()+r);
  }
}

void mergeSort_threads(std::vector<double>& v, int l, int r) {
  if (r-l > 512) {
    int m = (r + l) / 2;
    std::thread left_thread(mergeSort_threads, std::ref(v), l, m);
    //std::thread left_thread(fast_small_sort, v);
    mergeSort_threads(v, m, r);
    left_thread.join();
    inplace_merge(v.begin()+l, v.begin()+m, v.begin()+r);
  }
  else {
    fast_small_sort(v);
  }
}

template <typename T>
void merge_1(std::vector<T> v, std::vector<T> r) {

}

//template <typename T>
//void mergeSort(std::vector<T> v) {
void mergeSort(std::vector<double> v) {
  mergeSort_1(v, 0, v.size());
}

void mergeSort2(std::vector<double> v) {
  mergeSort_threads(v, 0, v.size());
}
