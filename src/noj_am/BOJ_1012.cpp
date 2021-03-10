#include <iostream>
using namespace std;

bool v[51][51];
int T, N, M, K, ans;
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};

bool dfs(int i, int j) {
  if (i < 0 || i >= N || j < 0 || j >= M) return false;
  if (v[i][j] == false) return false;
  v[i][j] = 0;
  for (int d = 0; d < 4; ++d) {
    int x = i + dx[d], y = j + dy[d];
    dfs(x, y);
  }
  return true;
}

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> T;
  while (T--) {
    cin >> N >> M >> K;
    for (int i = 0; i < K; ++i) {
      int x, y;
      cin >> x >> y;
      v[x][y] = 1;
    }
    ans = 0;
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < M; ++j) {
        if (dfs(i, j)) {
          ++ans;
        }
      }
    }
    cout << ans << '\n';
  }
}