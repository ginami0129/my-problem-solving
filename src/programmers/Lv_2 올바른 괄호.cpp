#include <string>
#include <stack>

using namespace std;

bool solution(string s)
{
  stack<char> check;
  bool answer = true;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == '(') {
      check.push(s[i]);
    } else if (!check.empty()){
      check.pop();
    } else {
      answer = false;
      break;
    }
  }
  if (!check.empty()) answer = false;
  return answer;
}
