#include <iostream>
#include <queue>
using namespace std;

queue<pair<pair<int, int>, int> > q;
int N, M, check[1001][1001][2], d[] = {1, -1, 0, 0};
char v[1001][1001];

int main(void) {
  int N, M;
  cin >> N >> M;
  for (int i = 0; i < N; ++i) {
    cin >> v[i];
  }
  q.push({{0, 0}, 1});
  check[0][0][1] = 1;
  while (!q.empty()) {
    int x = q.front().first.first, y = q.front().first.second;
    bool block = q.front().second;
    if (x == N - 1 && y == M - 1) {
      cout << check[x][y][block] << '\n';
      return 0;
    }
    for (int i = 0; i < 4; ++i) {
      int nx = x + d[i], ny = y + d[3 - i];
      if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
      if (v[nx][ny] == '0' && check[nx][ny][block] == 0) {
        check[nx][ny][block] = check[x][y][block] + 1;
        q.push({{nx, ny}, block});
      } else if (v[nx][ny] == '1' && block) {
        check[nx][ny][block - 1] = check[x][y][block] + 1;
        q.push({{nx, ny}, block - 1});
      }
    }
    q.pop();
  }
  cout << -1 << '\n';
}