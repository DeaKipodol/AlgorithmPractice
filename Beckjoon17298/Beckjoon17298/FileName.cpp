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
	}//�ڷ� �ϼ�
	for (int i = 0; i < n; ++i) {//laterseek���� �ڽź��� ū������ ��ã���ָ� ���� while�������� ū������ ã�� �ϰ� 
		//ã���� ���ÿ����� ���â ������Ʈ
		while (!laterseek.empty() && data_[laterseek.top()] < data_[i]) {
			result[laterseek.top()] = data_[i];
			laterseek.pop();
		}
		//����ų� �ڽź��� ū ������ ��ã������
		laterseek.push(i);//laterseek���� �ڽź��� ū ������ ��ã�� ģ���� ����.
	}
	for (int i = 0; i < n; i++) {
		std::cout << result[i] << " ";
	}
}