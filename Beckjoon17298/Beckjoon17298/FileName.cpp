#include <iostream>
#include<stack>
#include<vector>
int main() {
	std::stack<int> laterseek;
	int n;
	std::cin>>n;
	std::vector<int> data_(n);
	std::vector<int>result(n, -1);
	for (int i = 0; i < n; ++i) {
		std::cin >> data_[i];
	}//자료 완성
	for (int i = 0; i < n; ++i) {//laterseek에는 자신보다 큰정수를 못찾은애만 남음 while루프에서 큰정수를 찾게 하고 
		//찾으면 스택에빼고 결과창 업데이트
		while (!laterseek.empty() && data_[laterseek.top()] < data_[i]) {
			result[laterseek.top()] = data_[i];
			laterseek.pop();
		}
		//비었거나 자신보다 큰 정수를 못찾았을시
		laterseek.push(i);//laterseek에는 자신보다 큰 정수를 못찾은 친구만 남음.
	}
	for (int i = 0; i < n; i++) {
		std::cout << result[i] << " ";
	}
}