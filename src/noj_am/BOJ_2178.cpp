#include <iostream>
#include <queue>
using namespace std;

queue<pair<int, int> > q;
int v[110][110];
int N, M;
int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};

int main(void) {
  cin >> N >> M;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      scanf("%1d", &v[i][j]);
    }
  }
  q.push(make_pair(0, 0));
  while (!q.empty()) {
    int x = q.front().first, y = q.front().second;
    q.pop();
    for (int j = 0; j < 4; ++j) {
      int nx = x + dx[j], ny = y + dy[j];
      if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
      if (v[nx][ny] == 1) {
        v[nx][ny] = v[x][y] + 1;
        q.push(make_pair(nx, ny));
      }
    }
  }
  cout << v[N - 1][M - 1] << '\n';
}