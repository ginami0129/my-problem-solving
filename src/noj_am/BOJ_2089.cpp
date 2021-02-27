#include <iostream>
#define MAX 64
using namespace std;

int main(void) {
  int num, i = 0;
  int result[MAX] = {0};
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> num;
  if (num == 0) {
    cout << 0 << '\n';
  } else {
    for (i = 0; num != 0; ++i) {
      if (num % -2 == -1) {
        result[i] = 1;
        --num;
      } else {
        result[i] = num % -2;
      }
      num /= -2;
    }
    for (--i; i >= 0; --i) {
      cout << result[i];
    }
  }
}