#include <iostream>
#include <vector>
using namespace std;

int T, N, v[1001], ans;
vector<bool> visited(1001, false), finished(1001, false);

void dfs(int V) {
  visited[V] = true;
  int next = v[V];
  if (visited[next] == false) {
    dfs(next);
  } else if (finished[next] == false) {
    ++ans;
  }
  finished[V] = true;
}

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> T;
  while (T--) {
    cin >> N;
    for (int from = 1; from <= N; ++from) {
      int to;
      cin >> to;
      v[from] = to;
      visited[from] = finished[from] = false;
    }
    ans = 0;
    for (int i = 1; i <= N; ++i) {
      if (visited[i] == true) continue;
      dfs(i);
    }
    cout << ans << '\n';
  }
}