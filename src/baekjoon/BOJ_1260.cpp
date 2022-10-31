#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M, V;
vector<int> v[1001];
vector<bool> check(1001, false);

void dfs(int V) {
  if (check[V]) return;
  check[V] = true;
  cout << V << ' ';
  for (int i = 0; i < v[V].size(); ++i) {
    dfs(v[V][i]);
  }
}

void bfs(int V) {
  queue<int> q;
  q.push(V);
  check[V] = true;
  while (!q.empty()) {
    int front = q.front();
    q.pop();
    cout << front << ' ';
    for (int i = 0; i < v[front].size(); ++i) {
      int vertex = v[front][i];
      if (check[vertex] == true) continue;
      check[vertex] = true;
      q.push(vertex);
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
  for (int i = 0; i <= N; ++i) {
    sort(v[i].begin(), v[i].end());
  }
  dfs(V);
  cout << '\n';
  check.assign(N + 1, false);
  bfs(V);
  cout << '\n';
}