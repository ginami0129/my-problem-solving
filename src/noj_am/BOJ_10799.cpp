#include <iostream>
#include <string>
using namespace std;

int main(void) {
  string input;
  int top = 1;
  int result = 0;
  cin >> input;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  for (int i = 1; i < input.size(); ++i) {
    if (input[i] == '(') {
      ++top;
    } else {
      --top;
      result += (input[i - 1] == ')' ? 1 : top);
    }
  }
  cout << result << '\n';
}