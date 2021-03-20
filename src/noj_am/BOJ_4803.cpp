#include <iostream>
#include <vector>
using namespace std;

int n, m, j;
vector<int> v[501];
vector<int> d(501, 0);

bool dfs(int x, int p) {
  d[x] = true;
  for (int i = 0; i < v[x].size(); i++) {
    if (v[x][i] == p) continue;
    if (d[v[x][i]] == true) return true;
    if (dfs(v[x][i], x)) return true;
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
      d[i] = false;
    }
    for (int i = 0; i < m; ++i) {
      int from, to;
      cin >> from >> to;
      v[from].push_back(to);
      v[to].push_back(from);
    }
    int count = 0;
    for (int i = 1; i <= n; ++i) {
      if (d[i] == true) continue;
      count += (dfs(i, 0) ? 0 : 1);
    }
    cout << "Case " << j << ": ";
    if (count == 0) {
      cout << "No trees." << '\n';
    } else if (count == 1) {
      cout << "There is one tree." << '\n';
    } else {
      cout << "A forest of " << count << " trees." << '\n';
    }
  }
}