#include <algorithm>
#include <iostream>
#define MAX 25
using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

int dfs(char map[][MAX], int N, int i, int j) {
  if (i < 0 || i >= N || j < 0 || j >= N) return 0;
  if (map[i][j] == '0') return 0;
  map[i][j] = '0';
  int r = 1;
  for (int d = 0; d < 4; ++d) {
    r += dfs(map, N, i + dx[d], j + dy[d]);
  }
  return r;
}

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;
  char map[MAX][MAX] = {0};
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      cin >> map[i][j];
    }
  }

  int result[MAX * MAX] = {0};
  int r = 0;
  for (int temp, i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      if (map[i][j] == '0') continue;
      if ((temp = dfs(map, N, i, j))) {
        result[r++] = temp;
      }
    }
  }
  sort(result, result + r);
  cout << r << '\n';
  for (int i = 0; i < r; ++i) {
    cout << result[i] << '\n';
  }
}