#include <bits/stdc++.h>
using namespace std;

int n;
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
int a[100][100], d[100][100];
void bfs(int x, int y, int cnt);
int main(void) {
  scanf("%d", &n);
  queue<pair<int, int> > q;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      scanf("%d", &a[i][j]);
      if (a[i][j] == 1) q.push(make_pair(i, j));
    }
  }
  int cnt = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (a[i][j] == 1 && d[i][j] == 0) bfs(i, j, cnt++);
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      a[i][j] = 0;
    }
  }
  while (!q.empty()) {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();
    for (int i = 0; i < 4; ++i) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
      if (d[nx][ny] != 0) continue;
      d[nx][ny] = d[x][y];
      a[nx][ny] = a[x][y] + 1;
      q.push(make_pair(nx, ny));
    }
  }

  int ans = 987654321;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      for (int k = 0; k < 4; ++k) {
        int nx = i + dx[k];
        int ny = j + dy[k];
        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
        if (d[i][j] != d[nx][ny]) {
          if (ans > a[i][j] + a[nx][ny])
            ans = a[i][j] + a[nx][ny];
        }
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}

void bfs(int x, int y, int cnt) {
  queue<pair<int, int> > q;
  q.push(make_pair(x, y));
  d[x][y] = cnt;
  while (!q.empty()) {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();
    for (int i = 0; i < 4; ++i) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
      if (a[nx][ny] == 0 || d[nx][ny] != 0) continue;
      d[nx][ny] = cnt;
      q.push(make_pair(nx, ny));
    }
  }
  return;
}