#include <cstring>
#include <iostream>
#include <string>
#define SIZE 100
#define LENGTH 81
using namespace std;

int d[SIZE][SIZE][LENGTH];
int N, M, K, length, ans;
int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, -1, 1};
char map[SIZE][SIZE];
string word;

int dfs(int x, int y, int cnt) {
  if (cnt == length - 1) return 1;
  if (d[x][y][cnt] > -1) return d[x][y][cnt];
  d[x][y][cnt] = 0;
  int nx, ny;
  for (int i = 1; i <= K; ++i) {
    for (int j = 0; j < 4; ++j) {
      nx = x + dx[j] * i, ny = y + dy[j] * i;
      if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
      if (word[cnt + 1] != map[nx][ny]) continue;
      d[x][y][cnt] += dfs(nx, ny, cnt + 1);
    }
  }
  return d[x][y][cnt];
}

int main(void) {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  cin >> N >> M >> K;

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      cin >> map[i][j];
    }
  }
  memset(d, -1, sizeof(d));
  cin >> word;
  length = word.length();

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      if (map[i][j] == word[0]) ans += dfs(i, j, 0);
    }
  }
  cout << ans << '\n';

  return 0;
}