#include <iostream>
#include <string>
using namespace std;

int main(void) {
  int N, top = 0;
  string input;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N;
  while (N--) {
    cin >> input;
    for (int i = 0; i < input.size(); ++i) {
      if (input[i] == '(') {
        ++top;
      } else {
        --top;
        if (top < 0) break;
      }
    }
    cout << (top == 0 ? "YES" : "NO") << '\n';
    top = 0;
  }
}