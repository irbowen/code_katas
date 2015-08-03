#include <vector>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <algorithm>
#include <functional>
#include "merge_sort.h"

using namespace std;


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
  for (int i = 2; i < 128; i+=2 ) {
    cout << "Size: " << i << " ";
    //cout << "\tBubble: ";
    //double bubble_sort_time = timeSize(i, bubble_sort_vector);
    //cout << bubble_sort_time;
    //cout << "\t\tSelection: ";
    //double selection_sort_time = timeSize(i, selection_sort_vector);
    //cout << selection_sort_time;
    cout << "\t\tInsertion STL: ";
    double insertion_stl_time = timeSize(i, insertion_sort);
    cout << insertion_stl_time;
    cout << "\t\tInsertion Isaac: ";
    double insertion_isaac_time = timeSize(i, insertion_sort_vector);
    cout << insertion_isaac_time;
    //cout << "\t\tInsertion Internet: ";
    //double insertion_internet_time = timeSize(i, insertion_sort_internet);
    //cout << insertion_internet_time;
    //cout << "\t\t\tsort():";
    //double std_sort_time = timeSize(i, std_sort);
    //cout << std_sort_time;
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
