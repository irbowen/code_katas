#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>

using namespace std;

void prettyPrint(vector<vector<string>> m) {
  for (auto x : m) {
    for (auto y : x) {
        cout << y << " ";
    }
    cout << "\n";
  }
}

void readMatrixFromFile(vector<vector<string>> &m, string filename) {
  ifstream file;
  file.open(filename);
  string line;
  int row = 0;
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

void rotate(vector<vector<int>> m) {
    // move through each ring, from the outside in
    for (auto i = 0; i < m.size()/2; i++) {
      //move through each cell.  left top to right top, to bot right, to bot left, then move left top + 1
      for (auto j = 0; j < m.size(); j++) {
        int min, max;
        min = i;
        max = m.size() - i - 1;
        //Can't swap in order or we would just move top left around
        swap(m.at(min+j).at(min), m.at(min).at(max-j));
        swap(m.at(min).at(max-j), m.at(max-j).at(max));
        swap(m.at(max-j).at(max), m.at(max).at(min+j));
        //swap(m.at(max).at(min+j), m.at(min).at(min+j));
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
