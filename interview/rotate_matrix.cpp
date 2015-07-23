#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>

using namespace std;

void prettyPrint(vector<vector<string>> m) {
  cout << "Matrix:\n";
  for (auto x : m) {
    for (auto y : x) {
        cout << y << " ";
    }
    cout << "\n";
  }
  cout << endl;
}

void readMatrixFromFile(vector<vector<string>> &m, string filename) {
  ifstream file;
  file.open(filename);
  string line;
  while (getline(file, line)) {
    istringstream oss(line);
    string item;
    vector<string> row;
    while (oss >> item) {
        row.push_back(item);
    }
    m.push_back(row);
  }
}

template <typename T>
void cycle_clockwise(T& a, T& b, T& c, T& d) {
  T temp = d;
  d = c;
  c = b;
  b = a;
  a = temp;
}

template <typename T>
void rotate(vector<vector<T>>& m) {
    for (auto i = 0; i < m.size()/2; i++) {
      for (auto j = i; j < m.size() - i - 1; j++) {
        cycle_clockwise(m.at(i).at(j),
              m.at(j).at(m.size()-i-1),
              m.at(m.size()-i-1).at(m.size()-j-1),
              m.at(m.size()-j-1).at(i));
      }
    }
}

int main(int argc, char* argv[]) {
  string filename{argv[1]};
  vector<vector<string>> matrix;
  readMatrixFromFile(matrix, filename);
  prettyPrint(matrix);
  rotate(matrix);
  prettyPrint(matrix);
}
