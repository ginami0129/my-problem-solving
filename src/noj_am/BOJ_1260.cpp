#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> v[1001];
vector<bool> check(1001, false);
int N, M, V;

void dfs(int vertex) {
  if (check[vertex] == true) return;
  check[vertex] = true;
  cout << vertex << ' ';
  for (int i = 0; i < v[vertex].size(); ++i) {
    dfs(v[vertex][i]);
  }
}

void bfs(int vertex) {
  queue<int> q;
  q.push(vertex);
  check[vertex] = true;
  while (!q.empty()) {
    int front = q.front();
    cout << front << ' ';
    q.pop();
    for (int i = 0; i < v[front].size(); ++i) {
      int node = v[front][i];
      if (check[node] == true) continue;
      check[node] = true;
      q.push(node);
    }
  }
}

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> N >> M >> V;
  for (int i = 0; i < M; ++i) {
    int from, to;
    cin >> from >> to;
    v[from].push_back(to);
    v[to].push_back(from);
  }
  for (int i = 0; i < N; ++i) {
    sort(v[i].begin(), v[i].end());
  }
  dfs(V);
  cout << '\n';
  check.assign(N + 1, false);
  bfs(V);
  cout << '\n';
}
