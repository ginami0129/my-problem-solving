#include <iostream>
using namespace std;

bool v[51][51];
int T, M, N, K;
int d[] = {0, 0, -1, 1};

bool dfs(int x, int y) {
  if (x < 0 || y < 0 || x >= N || y >= M) return false;
  if (v[x][y] == false) return false;
  v[x][y] = false;
  for (int i = 0; i < 4; ++i) {
    dfs(x + d[i], y + d[3 - i]);
  }
  return true;
}

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> T;
  while (T--) {
    cin >> M >> N >> K;
    for (int i = 0; i < K; ++i) {
      int x, y;
      cin >> y >> x;
      v[x][y] = true;
    }
    int r = 0;
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < M; ++j) {
        if (dfs(i, j)) {
          ++r;
        }
      }
    }
    cout << r << '\n';
  }
}