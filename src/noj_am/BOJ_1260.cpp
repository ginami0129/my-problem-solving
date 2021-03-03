#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void dfs(vector<int> *v, int start, vector<bool> &check) {
  if (check[start] == true) return;
  check[start] = true;
  cout << start << ' ';
  for (int i = 0; i < v[start].size(); ++i) {
    dfs(v, v[start][i], check);
  }
}

void bfs(vector<int> *v, int start, vector<bool> &check) {
  queue<int> q;
  q.push(start);
  check[start] = true;
  cout << start << ' ';
  while (!q.empty()) {
    int front = q.front();
    q.pop();
    for (int i = 0; i < v[front].size(); ++i) {
      int node = v[front][i];
      if (check[node] == false) {
        q.push(node);
        check[node] = true;
        cout << node << ' ';
      }
    }
  }
}

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int N, M, V;
  cin >> N >> M >> V;
  vector<int> v[N + 1];
  for (int i = 0; i < M; ++i) {
    int from, to;
    cin >> from >> to;
    v[from].push_back(to);
    v[to].push_back(from);
  }
  for (int i = 0; i < N; ++i) {
    sort(v[i].begin(), v[i].end());
  }
  vector<bool> check(N + 1, false);
  dfs(v, V, check);
  cout << '\n';
  check.assign(N + 1, false);
  bfs(v, V, check);
  cout << '\n';
}