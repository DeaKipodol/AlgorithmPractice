#include<iostream>
#include<string>
#define M 1046527
#define L 14

char H[M][L];

int getChar(char ch) {
	if (ch == 'A') return 1;
	else if (ch == 'C') return 2;
	else if (ch == 'G') return 3;
	else if (ch == 'T') return 4;
	else return 0;
}

int getKey(char str[]) {
	int sum = 0, p = 1;
	for (int i = 0; i < strlen(str); i++) {
		sum = sum + p * (getChar(str[i]));
		p = p * 5;
	}
	return sum;
}
//is hash function
int h1(int key) {
	return key % M;
}
int h2(int key){return (key % (M - 1)) + 1;}
int find(char str[]) {
	int key,hash;
	key = getKey(str);
	for (int i = 0;; i++) {
		hash = (h1(key) + i * h2(key)) % M;
		if (strcmp(H[hash], str) == 0)return 1;//두 문자열이 동일 하면\
		//조건에안맞으면 계속 루프돔
		else if (strlen(H[hash]) == 0)//그러다 문자열이 0 즉, 비어있다면
		{
			return 0;
		}
	}
}
int insert(char str[]) {
	int key, i, h;
	key = getKey(str);
	for (i = 0;; i++) {
		h = (h1(key) + i * h2(key)) % M;
		if (strcmp(H[h], str) == 0) return 1;
		else if (strlen(H[h]) == 0) {
			strcpy_s(H[h], str);

			return 0;
		}
	}
}
int main() {
	int i, n, h;
	char str[L],com[9];
	for (i = 0; i < M; i++)H[i][0] = '\0';
	std::cin >> n;
	for (i = 0; i < n; i++) {
		std::cin >> com >> str;
		if (com[0] == 'i')//insert
		{
			insert(str);
		}
		else {//find
			if (find(str)) { std::cout << "true"; }
			else printf("false\n");
		}
	}
}