#include <iostream>
#include <stack>
#include <string>
using namespace std;

int OpPriority(char op);
/*
1. 피연산자 처리
1-1. 출력
2. 괄호 처리
2-1. '('이면 스택에 넣어준다.
2-2. ')' 이면 스택의 top이 ')'일때까지 pop하면서 그 값들을 출력
3. 연산자 처리
-> 높은 우선순위를 가진 연산자가 맨위에서 못나가게 막는다.
3-1. 스택이 비어있거나 스택의 top연산자가 입력보다 우선순위가 작을때까지
    스택의 top 연산자를 출력하고, pop한다.
3-2. 연산자를 스택에 넣어준다.
4. 스택에 남아있는 연산자 처리
4-1. 스택이 빌때까지 pop하면서 출력한다.
*/
int main(void) {
  string input;
  string postfix;
  stack<char> op;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> input;
  for (int i = 0; i < input.size(); ++i) {
    if (input[i] >= 'A' && input[i] <= 'Z') {
      postfix.push_back(input[i]);
    } else if (input[i] == '(') {
      op.push(input[i]);
    } else if (input[i] == ')') {
      while (op.top() != '(') {
        postfix.push_back(op.top());
        op.pop();
      }
      op.pop();
    } else {
      while(!(op.empty() || OpPriority(op.top()) < OpPriority(input[i]))) {
        postfix.push_back(op.top());
        op.pop();
      }
      op.push(input[i]);
    }
  }
  while (!op.empty()) {
    postfix.push_back(op.top());
    op.pop();
  }
  cout << postfix << '\n';
}

int OpPriority(char op) {
  if (op == '(' || op == ')') {
    return 0;
  } else if (op == '+' || op == '-') {
    return 1;
  } else if (op == '*' || op == '/') {
    return 2;
  }
}