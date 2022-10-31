#include <iostream>
using namespace std;

int main(void) {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  int m, n, ans = 0;
  ;
  cin >> m >> n;
  char arr[1001][1001] = {0};
  int d[1001][1001] = {0};
  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= n; ++j) {
      cin >> arr[i][j];
      d[i][j] = arr[i][j] - '0';
    }
  }

  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (d[i][j] == 0) continue;
      d[i][j] += min(d[i - 1][j - 1], min(d[i - 1][j], d[i][j - 1]));
      ans = max(ans, d[i][j]);
    }
  }
  cout << ans * ans << '\n';
  return 0;
}