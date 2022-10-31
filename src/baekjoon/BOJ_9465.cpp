#include <iostream>
#define MAX_SIZE 100001
using namespace std;

int main(void) {
  int T, n;
  int d[2][MAX_SIZE] = {0};
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> T;
  while (T--) {
    cin >> n;
    for (int i = 0; i < 2; i++) {
      for (int j = 1; j <= n; ++j) {
        cin >> d[i][j];
      }
    }
    for (int i = 2; i <= n; ++i) {
      for (int j = 0; j < 2; j++) {
        d[j][i] += max(d[1 - j][i - 1], d[1 - j][i - 2]);
      }
    }
    cout << max(d[0][n], d[1][n]) << '\n';
  }
}
