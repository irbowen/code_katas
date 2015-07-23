#include <vector>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <algorithm>
#include <functional>
/*
template <typename Container, typename Type>
void selection_sort(Container<Type>& v) {
  for (auto i = begin(v); i != end(v); i++) {
    auto min = &i;
    for (auto j = i; j != end(v); j++) {
      if (&j < min) {
        min = &j;
      }
    }
  }
}
*/
template <typename T>
void print_vector(std::vector<T> v) {
  for (auto x : v) {
    std::cout << x << " ";
  }
  std::cout << std::endl;
}

template <typename T>
void selection_sort_iterators(std::vector<T> v) {
  for (auto i = begin(v); i != end(v); i++) {
    auto min_value = &i;
    auto min_index = i;
    for (auto j = i; j != end(v); j++) {
      if (&j < min_value) {
        min_value = &j;
        min_index = j;
      }
    }
    std::swap(i, min_index);
    print_vector(v);
  }
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
  for (int i = 2; i < 40000; i = i * 2 ) {
    std::cout << "Size: " << i << " ";
    std::cout << "\tBubble sort: ";
    double f = timeSize(i, bubble_sort_vector);
    std::cout << "\tSlection sort: ";
    double s = timeSize(i, selection_sort_vector);
    std::cout << "\t\tFactor: " << f/s << " " << std::endl;
  }
  return 0;
}
