#include <iostream>
#define MAX 500
using namespace std;

int map[MAX][MAX], d[MAX][MAX];
int M, N;
int dx[4] = {1, 0, 0, -1}, dy[4] = {0, 1, -1, 0};

int dfs(int x, int y) {
  if (x == M - 1 && y == N - 1) return d[x][y] = 1;
  if (d[x][y] > -1) return d[x][y];
  d[x][y] = 0;
  int nx, ny;
  for (int i = 0; i < 4; ++i) {
    nx = x + dx[i], ny = y + dy[i];
    if (nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
    if (map[x][y] > map[nx][ny]) d[x][y] += dfs(nx, ny);
  }
  return d[x][y];
}

int main(void) {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  cin >> M >> N;
  for (int i = 0; i < M; ++i) {
    for (int j = 0; j < N; ++j) {
      cin >> map[i][j], --d[i][j];
    }
  }
  cout << dfs(0, 0) << '\n';
  return 0;
}