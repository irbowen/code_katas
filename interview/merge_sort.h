#include <algorithm>
#include <iostream>


//template <typename T>
//void mergeSort_1(std::vector<T>& v, int l, int r) {
void mergeSort_1(std::vector<double>& v, int l, int r) {
  if (r-l > 1) {
    auto m = (r + l) / 2;
    mergeSort_1(v, l, m);
    mergeSort_1(v, m, r);
    inplace_merge(v.begin()+l, v.begin()+m, v.begin()+r);
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
