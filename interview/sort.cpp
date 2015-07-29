#include <vector>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <algorithm>
#include <functional>
#include "merge_sort.h"

using namespace std;


template <typename T>
void print_vector(vector<T>& v) {
  for (auto x : v) {
    cout << x << " ";
  }
  cout << endl;
}

void selection_sort_vector(vector<double>& v) {
  for (auto i = 0; i < v.size(); i++) {
    auto min_value = v.at(i);
    auto min_index = i;
    for (auto j = i+1; j < v.size(); j++) {
      if (v.at(j) < min_value) {
        min_value = v.at(j);
        min_index = j;
      }
    }
    swap(v.at(i), v.at(min_index));
  }
}

void bubble_sort_vector(vector<double>& v) {
  bool swaps = true;
  while (swaps) {
    swaps = false;
    for (auto j = 0; j < v.size()-1; j++) {
      if (v.at(j) < v.at(j+1)) {
        swap(v.at(j), v.at(j+1));
        swaps = true;
      }
    }
  }
}

void insertion_sort_internet(vector<double>& v){
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

void insertion_sort_vector(vector<double>& v) {
    for (auto i = 0; i < v.size(); i++) {
      auto j = i;
      while (j > 0 && v[j] < v[j-1]) {
        swap(v[j], v[j-1]);
        j--;
      }
    }
}

void std_sort(vector<double>& v) {
  std::sort(v.begin(), v.end());
}

void insertion_sort(vector<double>& v) {
  for (auto i = begin(v); i != end(v); ++i)
    rotate(upper_bound(begin(v), i, *i), i, next(i));
}

auto timeSize(int size, function<void(vector<double>&)> sort_type) {
  vector<double> v(size);
  srand(time(0));
  for (auto& x : v) {
    x = rand() % (size * 5);
  }
  clock_t start;
  start = clock();
  sort_type(v);
  auto duration = (clock() - start)  / (double)(CLOCKS_PER_SEC / 1000);
  return duration;
}

int main() {
  for (int i = 2; i < 480000000; i = i * 2 ) {
    cout << "Size: " << i << " ";
    //cout << "\tBubble: ";
    //double bubble_sort_time = timeSize(i, bubble_sort_vector);
    //cout << bubble_sort_time;
    //cout << "\t\tSelection: ";
    //double selection_sort_time = timeSize(i, selection_sort_vector);
    //cout << selection_sort_time;
     //cout << "\t\tInsertion STL: ";
    //double insertion_stl_time = timeSize(i, insertion_sort);
    //cout << insertion_stl_time;
    //cout << "\t\tInsertion Isaac: ";
    //double insertion_isaac_time = timeSize(i, insertion_sort_vector);
    //cout << insertion_isaac_time;
    //cout << "\t\tInsertion Internet: ";
    //double insertion_internet_time = timeSize(i, insertion_sort_internet);
    //cout << insertion_internet_time;
    cout << "\t\t\tsort():";
    double std_sort_time = timeSize(i, std_sort);
    cout << std_sort_time;
    cout << "\t\tMergeSort():";
    double merge_sort_time = timeSize(i, mergeSort);
    cout << merge_sort_time;
    cout << "\t\tMergeSor2t():";
    double merge_sort_time2 = timeSize(i, mergeSort2);
    cout << merge_sort_time2;
    cout <<  endl;
  }

  return 0;
}
