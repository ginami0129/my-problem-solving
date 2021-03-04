#include <cmath>
#include <iostream>
#define MAX 10001
using namespace std;

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int M, N;
  cin >> M >> N;
  bool d[MAX] = {1, 1};
  for (int i = 2; i <= sqrt(MAX); ++i) {
    if (d[i] == true) continue;
    for (int j = i * i; j < MAX; j += i) {
      d[j] = true;
    }
  }
  int result = 0;
  int m = MAX;
  for (int i = M; i <= N; ++i) {
    if (d[i] == true) continue;
    m = min(m, i);
    result += i;
  }
  if (m == MAX) {
    cout << -1 << '\n';
  } else {
    cout << result << '\n';
    cout << m << '\n';
  }
}