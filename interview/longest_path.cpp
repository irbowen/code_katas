#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int longest_path_from_node(const vector<vector<int>>& graph, int index) {
  // Basiicaly, breadth first search
  // Keep track of whether a node has been visted or not
  vector<bool> visited(graph.size());
  queue<int> to_visit;
  to_visit.push(index);
  int last = 0;
  while (!to_visit.empty()) {
    int cur_index = to_visit.front();
    to_visit.pop();
    for (auto& v : graph.at(cur_index)) {
      if (!visited.at(v)) { 
        to_visit.push(v);
        visited.at(v) = true; } 
    }
    last = cur_index;
  }
  return last;
}

void longest_path_in_graph(const vector<vector<int>>& graph) {
  int start_node = 0, last_node = 0;
  start_node = longest_path_from_node(graph, 0);
  last_node = longest_path_from_node(graph, start_node);
  cout << "Longest path is: " << start_node << " " << last_node << endl;
}

int main() {
  vector<vector<int>> graph;
  graph.push_back({1,4,7});
  graph.push_back({0,2});
  graph.push_back({1,3,6});
  graph.push_back({2});
  graph.push_back({0,5});
  graph.push_back({4});
  graph.push_back({2});
  graph.push_back({0,8});
  graph.push_back({7,9});
  graph.push_back({8});
  longest_path_in_graph(graph);
}
