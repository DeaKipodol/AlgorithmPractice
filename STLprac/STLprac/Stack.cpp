/*#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main() {

	stack<int>S;
	int a, b, x;
	string s;
	while (cin >> s) {
		if (s[0] == '+') {
			a = S.top();
			S.pop();
			b = S.top();
			S.pop();
			S.push(a + b);
		}
		else if (s[0] == '-')
		{
			a = S.top();
			S.pop();
			b = S.top();
			S.pop();
			S.push(a - b);
		}
		else if (s[0] == '*') {
			a = S.top();
			S.pop();
			b = S.top();
			S.pop();
			S.push(a * b);
		}
		else { S.push(stoi(s)); }
	}
}
*/