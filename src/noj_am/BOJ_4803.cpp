#include <iostream>
#include <vector>
using namespace std;

int n, m, j, ans;
vector<int> v[501];
vector<bool> check(501, false);

bool dfs(int V, int p) {
  if (check[V] == true) return true;
  check[V] = true;
  for (int i = 0; i < v[V].size(); ++i) {
    int c = v[V][i];
    if (v[V][i] == p) continue;
    if (dfs(c, V) == true) return true;
  }
  return false;
}

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  while (true) {
    ++j;
    cin >> n >> m;
    if (n == 0 && m == 0) break;
    for (int i = 1; i <= n; ++i) {
      v[i].clear();
      check[i] = false;
    }
    for (int i = 1; i <= m; ++i) {
      int from, to;
      cin >> from >> to;
      v[from].push_back(to);
      v[to].push_back(from);
    }
    ans = 0;
    for (int i = 1; i <= n; ++i) {
      ans += !dfs(i, 0);
    }
    cout << "Case " << j << ": ";
    if (ans > 1) {
      cout << "A forest of " << ans << " trees." << '\n';
    } else if (ans == 1) {
      cout << "There is one tree." << '\n';
    } else {
      cout << "No trees." << '\n';
    }
  }
}