#include <iostream>
#define MAX 10001
using namespace std;

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  bool d[MAX] = {0};
  for (int i = 1; i < MAX; ++i) {
    if (d[i] == false) {
      cout << i << '\n';
    };
    int n = i;
    while (true) {
      int temp = n;
      while (temp) {
        n += temp % 10;
        temp /= 10;
      }
      if (n >= MAX || d[n] == true) break;
      d[n] = true;
    }
  }
}