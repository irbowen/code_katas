#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
	ostringstream oss;
	for (auto i = 1; i < 100; i++) {
		ostringstream temp;
		if (i % 3 == 0) {
			temp  << "fizz ";
		}
		if (i % 5 == 0) {
			temp  << "buzz ";
		}
		if (temp.str().empty()) {
			temp << i << " ";
		}
		oss << temp.str();
	}
	cout << oss.str();
}
