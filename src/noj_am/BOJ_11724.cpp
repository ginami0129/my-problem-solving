#include <iostream>
#include <vector>
using namespace std;

vector<int> g[1001];
vector<int> check(1001, false);
int N, M;

bool dfs(int node) {
  if (check[node] == true) return false;
  check[node] = true;
  for (int i = 0; i < g[node].size(); ++i) {
    dfs(g[node][i]);
  }
  return true;
}

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> N >> M;
  for (int i = 1; i <= M; ++i) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  int count = 0;
  for (int i = 1; i <= N; ++i) {
    count += (dfs(i) ? 1 : 0);
  }
  cout << count << '\n';
}