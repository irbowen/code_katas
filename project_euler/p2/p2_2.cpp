#include <iostream>

using namespace std;

int main() {
	int sum = 0;
	int first = 1, second = 1, temp = 0;	
	while (second < 4000000) {
		if (second % 2 == 0) {
			sum += second;
		}
		temp = second;
		second += first;
		first = temp;
		
	}
	cout << "Sum: " << sum << endl;
}
