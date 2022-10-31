#include <iostream>
#include <queue>
using namespace std;

queue<pair<int, int> > q;
int v[301][301];
int t, l, a, b;
int dx[] = {2, 1, 2, 1, -2, -1, -2, -1};
int dy[] = {-1, -2, 1, 2, 1, 2, -1, -2};

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> t;
  while (t--) {
    cin >> l;
    for (int i = 0; i < l; ++i) {
      fill_n(v[i], l, 0);
    }
    cin >> a >> b;
    q.push(make_pair(a, b));
    v[a][b] = 1;
    cin >> a >> b;
    while (!q.empty()) {
      int x = q.front().first, y = q.front().second;
      q.pop();
      for (int i = 0; i < 8; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= l || ny >= l) continue;
        if (v[nx][ny] == 0) {
          v[nx][ny] = v[x][y] + 1;
          q.push(make_pair(nx, ny));
        }
      }
    }
    cout << v[a][b] - 1 << '\n';
  }
}