#include<iostream>

using namespace std;
int* growArray(int* p_value, int* size);
void printArray(
	int* p_values,
	int size,
	int elements_set
);
int main() {
	int next_element = 0;
	int size = 10;
	int* p_values = new int[size];//�ϴ� ó���� size�� ũ�⸦ ���� �迭 ��������->�ü���� ���� ���� ���� ��������.
	int val;
	cout << "please enter a number: ";
	cin >> val;
	while (val > 0) {

		if (size == next_element + 1) {
			p_values = growArray(p_values, &size);
		}
		p_values[next_element] = val;
		next_element++;
		cout << "Current array values are : " << endl;
		printArray(p_values, size, next_element);
		cout << "Please enter a number(or 0 to exit)";
		cin >> val;
	}
	delete[]p_values;
}
	void printArray(int* p_values, int size, int elements_set) {
		//����ڰ� �Է��ҋ����� element_Set�� ũ��� �����Ѵ�. �׷��� ���� �迭�� ũ�Ⱑ
		//�ȴ�
		cout << "�迭�� ũ��: " << size << endl;
		cout << "���� �ָ� �ִ� �迭�� ��" << elements_set << endl;
		cout << "�迭�� �� ��" << endl;
		for (int i = 0; i < elements_set; ++i) {
			cout << "p_values[" << i << "] =" << p_values[i] << endl;
		}
	}
	//�迭�� ũ�⸦ ��� �ø� ���ִ°�? �ѹ� �ü������ ��û���� �޸𸮸� �� �Ҵ���� ���� ����.
	// ���ӵ� �޸� �ּҸ� ���� ����
	//�� ���� �ּҿ� �ٸ� ���μ����� �����Ͱ� �� �� �ֱ� �����̴�.
	// �׷��� �ƿ� �ٸ� �������� ū�޸𸮸� �Ҵ�ް� ���� �迭�� ���� �����Ѵ�.
	//�󸶸�ŭ �� ū�޸𸮸� �Ҵ� ������? ���� �ι��.
	//1.������ ��ū �迭�� ��ȯ-> �����ͷε� �ȴٰ�!
	int* growArray(int* p_values, int* size) {
		*size *= 2;//size�� �������ؼ� �� �ּҿ� �ִ� �����ͳ� 2�踦 �ض�.
		int* p_new_values = new int[*size];
		for (int i = 0; i < *size; i++) {
			p_new_values[i] = p_values[i];
		}
		delete[] p_values;
		return p_new_values;
	}
