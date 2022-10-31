#include <iostream>
#include <vector>
using namespace std;

int V, target, result;
vector<pair<int, int> > v[100001];
vector<int> check(100001, 0);

void dfs(int V, int d) {
  if (check[V] == true) return;
  check[V] = true;
  if (d > result) {
    target = V;
    result = d;
  }
  for (int i = 0; i < v[V].size(); ++i) {
    dfs(v[V][i].first, d + v[V][i].second);
  }
}

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> V;
  for (int i = 1; i <= V; ++i) {
    int from, to, w;
    cin >> from >> to;
    while (to > -1) {
      cin >> w;
      v[from].push_back({to, w});
      cin >> to;
    }
  }

  dfs(1, 0);
  check.assign(V + 1, false);
  dfs(target, 0);
  cout << result << '\n';
}