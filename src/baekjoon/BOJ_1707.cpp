#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int K, V, E;
vector<int> v[20001];
vector<int> check(20001, false);
queue<int> q;

bool bfs(int V) {
  q.push(V);
  check[V] = -1;
  while (!q.empty()) {
    int front = q.front();
    for (int i = 0; i < v[front].size(); ++i) {
      int node = v[front][i];
      if (check[node] == 0) {
        check[node] = -1 * check[front];
        q.push(node);
      } else if (check[node] == check[front]) {
        return false;
      }
    }
    q.pop();
  }
  return true;
}

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> K;
  while (K--) {
    cin >> V >> E;
    while (!q.empty()) q.pop();
    for (int i = 1; i <= V; ++i) {
      v[i].clear();
      check[i] = 0;
    }
    for (int i = 0; i < E; ++i) {
      int from, to;
      cin >> from >> to;
      v[from].push_back(to);
      v[to].push_back(from);
    }
    bool flag = true;
    for (int i = 1; i <= V && flag; ++i) {
      flag = (check[i] == 0 ? bfs(i) : flag);
    }
    cout << (flag ? "YES" : "NO") << '\n';
  }
}