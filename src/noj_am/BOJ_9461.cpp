#include <iostream>
#define MAX 101
using namespace std;

int main(void) {
  int T, N;
  long long P[MAX] = {0, 1, 1, 1, 2};
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  for (int i = 5; i <= MAX - 1; ++i) {
    P[i] = P[i - 1] + P[i - 5];
  }
  cin >> T;
  while (T--) {
    cin >> N;
    cout << P[N] << '\n';
  }
}