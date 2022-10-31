#include <iostream>
#include <queue>
using namespace std;

queue<pair<int, int> > q;
int v[1001][1001], dx[] = {1, -1, 0, 0}, dy[] = {0, 0, -1, 1};
int M, N;

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> M >> N;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      cin >> v[i][j];
      if (v[i][j] == 1) {
        q.push(make_pair(i, j));
      }
    }
  }
  while (!q.empty()) {
    int x = q.front().first, y = q.front().second;
    q.pop();
    for (int i = 0; i < 4; ++i) {
      int nx = x + dx[i], ny = y + dy[i];
      if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
      if (v[nx][ny] == 0) {
        v[nx][ny] = v[x][y] + 1;
        q.push(make_pair(nx, ny));
      }
    }
  }
  int r = 0;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      if (v[i][j] == 0) {
        cout << -1 << '\n';
        return 0;
      } else if (v[i][j] > -1) {
        r = max(r, v[i][j]);
      }
    }
  }
  cout << r - 1 << '\n';
}