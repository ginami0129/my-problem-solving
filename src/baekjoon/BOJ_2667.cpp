#include <algorithm>
#include <iostream>
using namespace std;

char v[26][26];
int ans[26 * 26], dx[] = {1, -1, 0, 0}, dy[] = {0, 0, -1, 1};
int N, a;

int dfs(int i, int j) {
  if (i < 0 || i >= N || j < 0 || j >= N) return 0;
  if (v[i][j] == '0') return 0;
  v[i][j] = '0';
  int r = 1;
  for (int d = 0; d < 4; ++d) {
    int x = i + dx[d], y = j + dy[d];
    r += dfs(x, y);
  }
  return r;
}

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> N;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      cin >> v[i][j];
    }
  }
  for (int r, i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      if ((r = dfs(i, j))) {
        ans[a++] = r;
      }
    }
  }
  sort(ans, ans + a);
  cout << a << '\n';
  for (int i = 0; i < a; ++i) {
    cout << ans[i] << '\n';
  }
}