#include <bits/stdc++.h>
#define MAX 401
#define M 1000000000
using namespace std;

int n, k, d[MAX][MAX] = {1};

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> n >> k;
  for (int i = 1; i <= n + k - 1; ++i) {
    d[i][0] = 1;
    for (int j = 1; j <= n; ++j) {
      d[i][j] = (d[i - 1][j] + d[i - 1][j - 1]) % M;
    }
  }
  cout << d[n + k - 1][n] << '\n';
}