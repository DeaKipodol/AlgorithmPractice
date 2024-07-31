#include <iostream>

int n, A[1000000];
bool binarysearch(int key) {
	int left = 0;
	int right = n;
	int mid;
	while (left < right) {
		mid = (left + right)/2;
		if (key == A[mid])return true;
		//loop
		if (key < A[mid]) {
			right = mid;
		}
		else if (key > A[mid])
			left = mid+1;
	}
	return false;
}
int main() {
	int i,q,key,sum=0;
	std::cin >> n;
	for (i = 0; i < n; i++) {
		std::cin >> A[i];
	}
	std::cin >> q;
	for (i = 0; i < q; i++) {
		std::cin >> key;
		if (binarysearch(key))sum++;
	}
	std::cout <<sum;
}