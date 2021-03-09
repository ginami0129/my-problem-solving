#include <iostream>
#define MAX 51
using namespace std;

int x[4] = {1, -1, 0, 0};
int y[4] = {0, 0, 1, -1};

bool dfs(bool map[][MAX], int N, int M, int i, int j) {
  if (i < 0 || i >= N | j < 0 || j >= M) return false;
  if (map[i][j] == false) return false;
  map[i][j] = false;
  for (int d = 0; d < 4; ++d) {
    dfs(map, N, M, i + x[d], j + y[d]);
  }
  return true;
}

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int T;
  cin >> T;
  int M, N, K;
  while (T--) {
    bool map[MAX][MAX] = {0};
    cin >> M >> N >> K;
    for (int i = 0; i < K; ++i) {
      int x, y;
      cin >> x >> y;
      map[y][x] = true;
    }
    int result = 0;
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < M; ++j) {
        if (dfs(map, N, M, i, j)) {
          ++result;
        };
      }
    }
    cout << result << '\n';
  }
}