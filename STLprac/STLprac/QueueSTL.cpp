#include<iostream>
#include<string>
#include<queue>
using namespace std;

int main() {

	int n, q, t;
	string name;
	queue<pair<string, int>>Process;
	cin >> n >> q;

	for (int i = 0; i < n; i++) {
		cin >> name >> t;
		Process.push(make_pair(name, t));
	}
	pair<string, int> search;
	int laps = 0, a;
	while (!Process.empty()) {
		search = Process.front(); Process.pop();
		a == min(search.second, q);
		search.second -= a;
		laps += a;
		if (search.second > 0) {
			Process.push(search);
		}
		else { cout << search.first << " " << laps << endl; }
		return 0;
	}
}
}