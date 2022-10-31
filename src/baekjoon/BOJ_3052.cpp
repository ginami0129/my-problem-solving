#include <iostream>
using namespace std;

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int num, count = 10;
  bool flag[42] = {0};
  while (count--) {
    cin >> num;
    flag[num % 42] = true;
  }
  count = 0;
  for (int i = 0; i < 42; ++i) {
    if (flag[i] == false) continue;
    ++count;
  }
  cout << count << '\n';
}