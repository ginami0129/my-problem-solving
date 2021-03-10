#include <iostream>
#include <queue>
using namespace std;

char v[101][101], dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, 1, -1};
queue<pair<int, int> > q;

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int N, M;
  cin >> N >> M;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      cin >> v[i][j];
    }
  }
  q.push(make_pair(0, 0));
  v[0][0] = '0';
  int count = 1;
  while (!q.empty()) {
    int size = q.size();
    for (int j = 0; j < size; ++j) {
      int x = q.front().first, y = q.front().second;
      if (x == N - 1 && y == M - 1) {
        cout << count << '\n';
      }
      q.pop();
      for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
        if (v[nx][ny] == '0') continue;
        v[nx][ny] = '0';
        q.push(make_pair(nx, ny));
      }
    }
    ++count;
  }
}