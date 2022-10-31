#include <iostream>
#define SIZE 2001
using namespace std;

int map[SIZE][SIZE];
int N, ans, x1, y1, x2, y2;
int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, -1, 1};

void dfs(int x, int y) {
  int nx, ny;
  map[x][y] = 2;
  for (int i = 0; i < 4; ++i) {
    nx = x + dx[i], ny = y + dy[i];
    if (nx < 0 || ny < 0 || nx >= SIZE || ny >= SIZE) continue;
    if (map[nx][ny] == 1) {
      dfs(nx, ny);
    }
  }
}

int main(void) {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  cin >> N;

  for (int i = 0; i < N; ++i) {
    cin >> x1 >> y1 >> x2 >> y2;
    x1 = (x1 + 500) * 2, y1 = (y1 + 500) * 2, x2 = (x2 + 500) * 2,
    y2 = (y2 + 500) * 2;
    for (int j = x1; j <= x2; ++j) map[j][y1] = map[j][y2] = true;
    for (int k = y1 + 1; k < y2; ++k) map[x1][k] = map[x2][k] = true;
  }

  for (int i = 0; i < SIZE; ++i) {
    for (int j = 0; j < SIZE; ++j) {
      if (map[i][j] == 1) dfs(i, j), ++ans;
    }
  }

  if (map[SIZE / 2][SIZE / 2] == 2) --ans;
  cout << ans << '\n';
  return 0;
}