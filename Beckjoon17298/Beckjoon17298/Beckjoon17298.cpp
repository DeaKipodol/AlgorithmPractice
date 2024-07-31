/*#include <iostream>
#include<vector>

std::vector<int> vec;
int main()
{
	int n;
    std::cin >> n;
	vec.resize(n);
	for (int i = 0; i < n; i++) {
		std::cin >> vec [i];
	}
	int i = 2;
	for (std::vector<int>::iterator it = vec.begin(), end = vec.end(),it2=vec.begin()+1; it != end; ++it,++i) {
		
		while (*it >= *it2) {
			++it2;
			if (it2 == end)break;
		}
		
		if (it2 == end) {
			*it = -1;
			if (vec.begin() + i == end) {
				*(it + 1) = -1; break;
			}
			it2 = vec.begin() + i;
		}
		else {
			*it = *it2;
			if (vec.begin() + i == end) {
				*(it + 1) = -1; break;
			}
			it2 = vec.begin() + i;
		}
	}
	for (int z = 0; z < n; z++) {
		std::cout << vec[z]<<" ";
	}
}

*/