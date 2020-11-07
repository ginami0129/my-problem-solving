#include <iostream>
#include <stack>
using namespace std;
/*
1. 피연산자처리
1-1. 스택에 넣는다.
2. 연산자처리
2-1. stack을 두번 팝하여 나온 피연산자를 연산자에따라 계산한다.
2-2. 그 결과를 피연산자에 넣는다.
3. 결과 출력
피연산자의 스택의 top출력
*/
int main(void) {
  string postfix;
  stack<int> result;
  int op1, op2;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> postfix;
  for (int i = 0; i < postfix.size(); ++i) {
    if (postfix[i] >= '0' && postfix[i] <= '9') {
      result.push(postfix[i] - '0');
    } else {
      op2 = result.top();
      result.pop();
      op1 = result.top();
      result.pop();
      switch (postfix[i]) {
        case '+':
          result.push(op1 + op2);
          break;
        case '-':
          result.push(op1 - op2);
          break;
        case '*':
          result.push(op1 * op2);
          break;
        case '/':
          result.push(op1 / op2);
          break;
      }
    }
  }
  cout << result.top() << '\n';
}