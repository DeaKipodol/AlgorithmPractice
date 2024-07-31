#include <iostream>
#include <array>

using namespace std;

int main() {
	array<int, 100> myArray;
	for (int i = 1; i <= 100; i++) {
		myArray[i - 1] = i;
	}

	for (int i : myArray) {
		cout << i << " ";
	}
	return 0;
}