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
	int* p_values = new int[size];//일단 처음은 size의 크기를 가진 배열 동적생성->운영체제가 지금 새로 공간 마련해줌.
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
		//사용자가 입력할떄마다 element_Set의 크기는 증가한다. 그래서 이제 배열의 크기가
		//된다
		cout << "배열의 크기: " << size << endl;
		cout << "가장 멀리 있는 배열의 값" << elements_set << endl;
		cout << "배열에 든 값" << endl;
		for (int i = 0; i < elements_set; ++i) {
			cout << "p_values[" << i << "] =" << p_values[i] << endl;
		}
	}
	//배열의 크기를 어떻게 늘릴 수있는가? 한번 운영체제에게 요청받은 메모리를 더 할당받을 수는 없다.
	// 연속된 메모리 주소를 얻은 다음
	//그 다음 주소에 다른 프로세스의 데이터가 올 수 있기 때문이다.
	// 그래서 아예 다른 기존보다 큰메모리를 할당받고 이전 배열의 값을 복사한다.
	//얼마만큼 더 큰메모리를 할당 받을까? 보통 두배다.
	//1.공간이 더큰 배열을 반환-> 포인터로도 된다고!
	int* growArray(int* p_values, int* size) {
		*size *= 2;//size를 역참조해서 그 주소에 있는 데이터네 2배를 해라.
		int* p_new_values = new int[*size];
		for (int i = 0; i < *size; i++) {
			p_new_values[i] = p_values[i];
		}
		delete[] p_values;
		return p_new_values;
	}
