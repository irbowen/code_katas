#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

int singleNumber(vector<int>& nums) {
	unordered_map<int, int> word_count;
	for (auto& item : nums) {
		word_count[item]++;
	}
	for (auto& item : nums) {
		if (word_count[item] == 1) {
			return item;
		}
	}
}

int main() {
	vector<int> data {2, 2, 1, 1, 3};
	cout << singleNumber(data) << endl;
	return 0;
}