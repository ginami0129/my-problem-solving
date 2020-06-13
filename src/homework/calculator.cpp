/********************************************************************************
1.4 산술식 평가: calculator구현
앞서 구현한 generic stackClass를 이용하여 
산술식을 계산하는 프로그램의 pseudocode와 c++ 코드 calculator.cpp을 작성하시오.
피연산자를 저장하는 stackClass<double>과 연산자를 저장하는 stackClass<string>
를 이용하면 된다.
입력 token은 white space로 구분되며, 피연사자는 실수형, 연산자는 사칙연산
인 *, +, -, /외에 log, sqrt, pow함수로 추가로 주어지고, 계산의 우선순위를
위해 열린 괄호와 닫힌 괄호 (, )가 하나의 token으로 주어진다. argument 인자
간의 구분을 위해 ,이 사용된다.
다음은 입력의 예이다.
---------------------------------------------------
( 1 + ( ( 5 + 8 ) * ( 10 + 7.5 ) ) )
( ( ( 2 + pow ( 5.0 , 3.0 ) ) + log ( 7.0 ) ) / 3.0 )
( ( 2 + sqrt ( 10.0 ) ) * ( log ( 2.0 ) + 5 ) )
---------------------------------------------------
또한, 다음과 같이 문법에 맞지 않은 식이 입력되면 적절한 message로 syntax
error를 출력해야 한다.
---------------------------------------------------
( 5 + 6
pow ( 6 7 ) + log ( 5 )
( 4 + 2 ) * 10 )
---------------------------------------------------
********************************************************************************/
#include <iostream>
#include <sstream>
#include <string>
#include <stack>
#include <cmath>
using namespace std;
/* 연산자인지 확인하는 함수
1. op가 +, -, *, /, (, pow, sqrt, log 중에 하나라면 연산자
2. 그 외의 경우는 연산자가 아니다. 
*/
bool IsOperator(string op);
/* pow, sqrt, log 문을 중위표현으로 변경해주는 함수
pow ( 2 , 3 ) => ( 2 pow 3 ) 
sqrt ( 3 ) => ( 2 sqrt 3 )
log ( 4 ) => ( 2 log 4 )

, 연산자를 포함하는 함수는 pow 하나이므로 , 를 pow로 변경한다.
나머지는 "2 input "으로 변경해서 넣고 "( "다음에 넣는다.

1. input이 "log", "sqrt" 중 하나라면
1-1. 스택에 "2 log ", "2 sqrt "중 하나를 넣는다.
2. input이 ","이라면
2-1. 스택에 "pow "를 넣는다.
3. input이 "(" 이라면, 
3-1. 결과에 "( " + 스택의 맨 위에있는 함수명을 넣는다.
4. input이 pow가 아닌 모든 경우에대해
4-1. 결과에 넣는다.
*/
string ToInfix(string &input);
/* 중위표현 연산하는 함수
1. 함수 때문에 포함된 전위표현들을 중위표현으로 변환한다.
2. 공백에 대하여 input을 분리한다.
3. 중위표현 연산을 한다.
3-1. input이 연산자라면 연산자 스택에 넣는다.
3-2. input이 ")"이라면
     숫자 스택에서 숫자 두개를 가져와서
     input연산자로 연산한다.
     연산결과는 숫자 스택에 넣는다.
     연산자 스택 2번 pop한다.(연산자, 괄호)
     숫자 스택 연산자 스택 크기가 2이상이어야 성립
3-3 input이 숫자라면
    숫자 스택에 넣는다.
4. 숫자스택의 맨위가 결과이다.
*/
string Calculator(string &input);
/* 연산자에 따라 연산하는 함수 */
double Calculate(const double &op1, const double &op2, const string &how);

int main(void) {
  string input;
  getline(cin, input);
  cout << Calculator(input) << '\n';
}

bool IsOperator(string op) {
  if (op == "+" || op == "-" || op == "*" || op == "/" || 
      op == "(" || op == "pow" || op == "sqrt" || op == "log") {
    return true;
  } else {
    return false;
  }
}

string ToInfix(string &input) {
  stringstream ss(input);
  string infix = "";
  stack<string> op; 
  while (ss >> input) {
    if (input == "log" || input == "sqrt") {
      op.push("2 " + input + " ");
    } else if (input == ",") {
      infix += "pow ";
    } else if (input == "(" && !op.empty()) {
      infix += input + " " + op.top();
      op.pop();
    } else if (input != "pow"){
      infix += input + " ";
    }
  }
  return infix;
}

string Calculator(string &input) {
  stringstream ss(ToInfix(input));
  stack<double> num;
  stack<string> oprtr;
  double result;
  double op[2];
  while (ss >> input) {
    if (IsOperator(input)) {
      oprtr.push(input);
    } else if (input == ")") {
      if (num.size() < 2 || oprtr.size() < 2) return "syntax error";
      for (int i = 1; i >= 0; --i) {
        op[i] = num.top();
        num.pop();
      }
      num.push(Calculate(op[0], op[1], oprtr.top()));
      oprtr.pop();
      oprtr.pop();
    } else {
      num.push(stod(input));
    }
  }
  return (num.size() == 1 ? to_string(num.top()) : "syntax error");
}

double Calculate(const double &op1, const double &op2, const string &how) {
  if (how == "+") {
    return op1 + op2;
  } else if (how == "-") {
    return op1 - op2;
  } else if (how == "*") {
    return op1 * op2;
  } else if (how == "/") {
    return op1 / op2;
  } else if (how == "pow") {
    return pow(op1, op2);
  } else if (how == "sqrt") {
    return sqrt(op2);
  } else if (how == "log") {
    return log(op2);
  }
}