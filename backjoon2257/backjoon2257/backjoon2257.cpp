
#include <iostream>
#include <string>
#include <stack>

std::stack<int> Stack;



void printEnd() {
    int a,b;
    while (Stack.size()>1) {
        a = Stack.top();
        Stack.pop();
        b = Stack.top();
        Stack.pop();
        Stack.push(a + b);
        a = Stack.top();
}
  

    a = Stack.top();
    std::cout << a;
}

int main()
{
    int a, b;
   
    std:: string st;
    std::cin >> st;
    for (char& i : st) {
        
        if (i == 'O') Stack.push(16);
        else if (i == 'C')Stack.push(12);
        else if (i == 'H')Stack.push(1);
        else if (i == '(')Stack.push(0);
        else if (i == ')') { 
            //괄호 제거시술
            while ( Stack.top() != 0) {
                a = Stack.top();
                Stack.pop();
                if (Stack.top() == 0) {
                    //0제거
                    Stack.pop();
                    Stack.push(a);
                    break;

                }
                else {
                    b = Stack.top();
                    Stack.pop();
                    Stack.push(a + b);
                }
            }
            
           
            
        }
        else if (i >= '2' && i <= '9') {
             a = Stack.top();
            Stack.pop();
            Stack.push((i-'0') * a); }
    }
   
    printEnd();

}


