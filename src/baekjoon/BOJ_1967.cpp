#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int> > v[10001];
vector<bool> check(10001, false);
int n, target, result;

void dfs(int node, int sum) {
  if (check[node] == true) return;
  check[node] = true;
  if (sum > result) {
    result = sum;
    target = node;
  }
  for (int i = 0; i < v[node].size(); ++i) {
    dfs(v[node][i].first, sum + v[node][i].second);
  }
}

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> n;
  int from, to, weight;
  while (cin >> from >> to >> weight) {
    v[from].push_back({to, weight});
    v[to].push_back({from, weight});
  }
  dfs(1, 0);
  check.assign(n + 1, 0);
  dfs(target, 0);
  cout << result << '\n';
}