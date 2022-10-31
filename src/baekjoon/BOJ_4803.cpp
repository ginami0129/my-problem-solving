#include <iostream>
#include <vector>
using namespace std;

vector<int> v[501];
vector<int> check(501, 0);
int n, m;

bool dfs(int V, int p) {
  check[V] = true;
  for (int i = 0; i < v[V].size(); ++i) {
    int next = v[V][i];
    if (next == p) continue;
    if (check[next] == true) return true;
    if (dfs(next, V) == true) return true;
  }
  return false;
}

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  for (int step = 1;; ++step) {
    cin >> n >> m;
    if (n == 0 && m == 0) break;
    for (int i = 1; i <= n; ++i) {
      v[i].clear();
      check[i] = false;
    }
    for (int i = 0; i < m; ++i) {
      int from, to;
      cin >> from >> to;
      v[from].push_back(to);
      v[to].push_back(from);
    }
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
      if (check[i] == true) continue;
      cnt += !dfs(i, 0);
    }
    cout << "Case " << step << ": ";
    if (cnt == 0) {
      cout << "No trees." << '\n';
    } else if (cnt == 1) {
      cout << "There is one tree." << '\n';
    } else {
      cout << "A forest of " << cnt << " trees." << '\n';
    }
  }
}