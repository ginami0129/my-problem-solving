#include <iostream>
#include <queue>
using namespace std;

int M, N, H;
int v[101][101][101];
int dx[] = {1, -1, 0, 0, 0, 0};
int dy[] = {0, 0, 1, -1, 0, 0};
int dz[] = {0, 0, 0, 0, 1, -1};
queue<pair<int, pair<int, int> > > q;

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
    int x = q.front().first;
    int y = q.front().second.first, z = q.front().second.second;
    q.pop();
    for (int i = 0; i < 6; ++i) {
      int nx = x + dx[i], ny = y + dy[i], nz = z + dz[i];
      if (nx < 0 || nx >= H || ny < 0 || ny >= N || nz < 0 || nz >= M) continue;
      if (v[nx][ny][nz] == 0) {
        q.push(make_pair(nx, make_pair(ny, nz)));
        v[nx][ny][nz] = v[x][y][z] + 1;
      }
    }
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