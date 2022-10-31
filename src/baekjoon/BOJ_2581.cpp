#include <iostream>
using namespace std;

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int M, N;
  cin >> M >> N;
  M = max(2, M);
  int result = 0;
  int m = N;
  for (int i = N; i >= M; --i) {
    int j = 2;
    for (; j * j <= i; ++j) {
      if (i % j == 0) {
        break;
      }
    }
    if (j * j > i) {
      result += i;
      m = i;
    }
  }
  if (result == 0) {
    cout << -1 << '\n';
  } else {
    cout << result << '\n';
    cout << m << '\n';
  }
}