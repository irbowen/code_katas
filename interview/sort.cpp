#include <vector>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <algorithm>
#include <functional>

template <typename T>
void print_vector(std::vector<T> v) {
  for (auto x : v) {
    std::cout << x << " ";
  }
  std::cout << std::endl;
}

void selection_sort_vector(std::vector<int>& v) {
  for (auto i = 0; i < v.size(); i++) {
    auto min_value = v.at(i);
    auto min_index = i;
    for (auto j = i+1; j < v.size(); j++) {
      if (v.at(j) < min_value) {
        min_value = v.at(j);
        min_index = j;
      }
    }
    std::swap(v.at(i), v.at(min_index));
  }
}

void bubble_sort_vector(std::vector<int>& v) {
  bool swaps = true;
  while (swaps) {
    swaps = false;
    for (auto j = 0; j < v.size()-1; j++) {
      if (v.at(j) < v.at(j+1)) {
        std::swap(v.at(j), v.at(j+1));
        swaps = true;
      }
    }
  }
}

void insertion_sort_internet(std::vector<int>& v){
  int j, temp;
  for (int i = i; i < v.size(); i++){
    j = i;
    while (j > 0 && v[j] < v[j-1]){
      temp = v[j];
      v[j] = v[j-1];
      v[j-1] = temp;
      j--;
    }
  }
}

void insertion_sort_vector(std::vector<int>& v) {
    for (auto i = 0; i < v.size(); i++) {
      auto j = i;
      while (j > 0 && v[j] < v[j-1]) {
        std::swap(v[j], v[j-1]);
      }
    }
}

void insertion_sort(std::vector<int> v) {
  for (auto i = begin(v); i != end(v); ++i)
    std::rotate(std::upper_bound(begin(v), i, *i), i, std::next(i));
}

auto timeSize(int size, std::function<void(std::vector<int>&)> sort_type) {
  std::vector<int> v(size);
  std::srand(std::time(0));
  for (auto& x : v) {
    x = std::rand() % (size * size);
  }
  std::clock_t start;
  start = std::clock();
  sort_type(v);
  auto duration = (std::clock() - start)  / (double)(CLOCKS_PER_SEC / 1000);
  std::cout << " Time: " << duration << " ms";
  return duration;
}

int main() {
  for (int i = 2; i < 60000; i = i * 2 ) {
    std::cout << "Size: " << i << " ";
    std::cout << "\tBubble sort: ";
    double f = timeSize(i, bubble_sort_vector);
    std::cout << "\tSlection sort: ";
    double s = timeSize(i, selection_sort_vector);
    std::cout << "\t\tFactor: " << f/s << " " << std::endl;
  }
  for (int i = 2; i < 60000; i = i * 2 ) {
    std::cout << "Size: " << i << " ";
    std::cout << "\tInsertion STL sort: ";
    double f = timeSize(i, insertion_sort);
    std::cout << "\tInsertion Loop and swap sort: ";
    double s = timeSize(i, insertion_sort_vector);
    std::cout << "\tInsertion Internet and swap sort: ";
    double t = timeSize(i, insertion_sort_internet);
    std::cout << "\t\tFactor: " << f/s << " " << std::endl;
  }

  return 0;
}
