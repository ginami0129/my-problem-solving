#include <iostream>
#define MAX 100001
using namespace std;

int main(void) {
  int top = 0, result = 0;
  char input[MAX] = {0};
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> input;
  for (int i = 0; input[i]; ++i) {
    if (input[i] == '(') {
      ++top;
    } else {
      --top;
      result += input[i - 1] == ')' ? 1 : top;
    }
  }
  cout << result << '\n';
}