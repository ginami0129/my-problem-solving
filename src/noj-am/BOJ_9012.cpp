#include <iostream>
#include <stack>
#include <string>
using namespace std;

string IsCorrect(const string &input) {
  stack<char> check;
  for (int i = 0; i < input.size(); ++i) {
      if (input[i] == '(' || input[i] == '[') {
        check.push(input[i]);
      } else if (check.empty()) {
        return "NO";
      } else if(input[i] == ')' && check.top() == '(') {
        check.pop();
      } else if (input[i] == ']' && check.top() == '[') {
        check.pop();
      }
    }
    return check.empty() ? "YES" : "NO";
}

int main(void) {
  int T;
  string input;
  stack<char> check;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> T; 
  cin.get();
  while (T) {
    cin >> input;
    cin.get();
    cout << IsCorrect(input) << '\n';
    --T;
  }
}