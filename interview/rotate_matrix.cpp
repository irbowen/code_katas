#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>

using namespace std;


void rotate(vector<vector<int>> m) {
    for (auto i = 0; i < m.size()/2; i++) {
        
    }    
}

int main(int argc, char* argv[]) {
    string filename{argv[1]};
    ifstream file;
    file.open(filename);
    string line;
    int row = 0;

    vector<vector<string>> matrix;

    while (getline(file, line)) {
        istringstream oss(line);
        string item;
        vector<string> row;
        while (oss >> item) {
            row.push_back(item);
        }
        matrix.push_back(row);
    }

    for (auto x : matrix) {
        for (auto y : x) {
            cout << y << " ";
        }
        cout << "\n";
    }

}
