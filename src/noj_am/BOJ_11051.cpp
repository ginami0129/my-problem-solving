#include <bits/stdc++.h>
#define MAX 1001
using namespace std;

int n, k, c[MAX][MAX] = {1};
int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    c[i][0] = 1;
    for (int j = 1; j <= i; ++j) {
      c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % 10007;
    }
  }
  cout << c[n][k] << '\n';
}