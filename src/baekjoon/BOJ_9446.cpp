#include <iostream>
#include <vector>
using namespace std;

int T, n, to, ans;
int C[100001];
vector<bool> visited(100001, false);
vector<bool> finished(100001, false);

void dfs(int node) {
  visited[node] = true;
  int c = C[node];
  if (visited[c] == false) {
    dfs(c);
  } else if (finished[c] == false) {
    for (int i = c; i != node; i = C[i]) {
      ++ans;
    }
    ++ans;
  }
  finished[node] = true;
}

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  cin >> T;
  while (T--) {
    cin >> n;
    for (int from = 1; from <= n; ++from) {
      visited[from] = finished[from] = false;
      cin >> to;
      C[from] = to;
    }
    ans = 0;
    for (int i = 1; i <= n; ++i) {
      if (visited[i] == false) {
        dfs(i);
      }
    }
    cout << n - ans << '\n';
  }
}