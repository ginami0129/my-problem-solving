#include <iostream>
#include <queue>
using namespace std;

queue<pair<int, pair<int, int> > > q;
int v[101][101][101];
int d[10] = {1, -1, 0, 0, 0, 0, 1, -1, 0, 0};
int M, N, H;

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> M >> N >> H;
  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < N; ++j) {
      for (int k = 0; k < M; ++k) {
        cin >> v[i][j][k];
        if (v[i][j][k] == 1) {
          q.push(make_pair(i, make_pair(j, k)));
        }
      }
    }
  }
  while (!q.empty()) {
    int x = q.front().first, y = q.front().second.first, z = q.front().second.second;
    for (int i = 0; i < 6; ++i) {
      int nx = x + d[i], ny = y + d[i + 2], nz = z + d[i + 4];
      if (nx < 0 || ny < 0 || nz < 0 || nx >= H || ny >= N || nz >= M) continue;
      if (v[nx][ny][nz] == 0) {
        q.push(make_pair(nx, make_pair(ny, nz)));
        v[nx][ny][nz] = v[x][y][z] + 1;
      }
    }
    q.pop();
  }
  int r = 0;
  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < N; ++j) {
      for (int k = 0; k < M; ++k) {
        if (v[i][j][k] == 0) {
          cout << -1 << '\n';
          return 0;
        } else if (v[i][j][k] > -1) {
          r = max(r, v[i][j][k]);
        }
      }
    }
  }
  cout << r - 1 << '\n';
}