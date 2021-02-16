#include <iostream>
#define MAX 1001
using namespace std;

int main(void) {
  int N;
  int P[MAX] = {0};
  int d[MAX] = {0};
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N;
  for (int i = 1; i <= N; ++i) {
    cin >> P[i];
    for (int j = 1; j <= i; ++j) {
      d[i] = max(d[i], d[i - j] + P[j]);
    }
  }
  cout << d[N] << '\n';
}