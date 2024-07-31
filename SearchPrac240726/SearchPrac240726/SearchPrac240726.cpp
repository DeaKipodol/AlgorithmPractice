/*#include <iostream>
int search(int A[], int n, int key) {
    int i = 0;
    A[n] = key;
    while (A[i] != key)i++;
        return i != n;
}//A안에 key가 있다면 그 값이 있는 인덱스(정수)반환 없다면false반환
int main()
{
    int n, A[10000 + 1],q,i,key,sum=0;
    std::cin >> n;
    for ( i= 0; i < n;i++) {
        std::cin >> A[i];
    }
    std::cin >> q;
    for (i = 0; i < q; i++) {
        std::cin >> key;
        if (search(A, n, key)) { sum++; }
    }
    std::cout << sum;
}
*/