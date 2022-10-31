#include <iostream>
#define MAX 20

using namespace std;

int R, C, ans = 0;
char map[MAX][MAX];
bool flag[26];
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

void dfs(int x, int y, int cnt) {
  ans = max(cnt, ans);
  int nx, ny, index;
  for (int i = 0; i < 4; ++i) {
    nx = x + dx[i], ny = y + dy[i];
    if (nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
    index = map[nx][ny] - 'A';
    if (flag[index] == false) {
      flag[index] = true;
      dfs(nx, ny, cnt + 1);
      flag[index] = false;
    }
  }
  return;
}

int main(void) {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  cin >> R >> C;
  for (int i = 0; i < R; ++i) {
    for (int j = 0; j < C; ++j) {
      cin >> map[i][j];
    }
  }
  flag[map[0][0] - 'A'] = true;
  dfs(0, 0, 1);
  cout << ans << '\n';
  return 0;
}