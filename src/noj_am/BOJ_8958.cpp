#include <iostream>
using namespace std;

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N;
  char input[80] = {0};
  cin >> N;
  while (N--) {
    cin >> input;
    int result = 0, count = 0;
    for (int i = 0; input[i]; ++i) {
      count = input[i] == 'O' ? count + 1 : 0;
      result += count;
    }
    cout << result << '\n';
  }
}