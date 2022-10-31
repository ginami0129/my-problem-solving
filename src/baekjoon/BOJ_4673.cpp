#include <iostream>
#define SIZE 15000
#define MAX 10001
using namespace std;

int d(int n) {
  int result = n;
  while (n > 0) {
    result += n % 10;
    n /= 10;
  }
  return result;
}

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  bool flag[SIZE] = {false};
  for (int i = 1; i < MAX; ++i) {
    if (flag[i] == false) {
      cout << i << '\n';
    }
    flag[d(i)] = true;
  }
}