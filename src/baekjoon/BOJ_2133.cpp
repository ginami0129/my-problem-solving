#include <iostream>
#define MAX 31
using namespace std;

int main(void) {
  int N;
  int d[MAX] = {1};
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N;
  d[2] = 3;
  for (int i = 4; i <= N; i += 2) {
    d[i] = d[i - 2] * 3;
    for (int j = 4; j <= i; j += 2) {
      d[i] += d[i - j] * 2;
    }
  }
  cout << d[N] << '\n';
}