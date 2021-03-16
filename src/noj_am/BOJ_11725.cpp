#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N;
vector<int> v[100001];
vector<int> check(100001, 0);
queue<int> q;

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> N;
  for (int i = 0; i < N - 1; ++i) {
    int from, to;
    cin >> from >> to;
    v[from].push_back(to);
    v[to].push_back(from);
  }
  q.push(1);
  check[1] = -1;
  while (!q.empty()) {
    int front = q.front();
    for (int i = 0; i < v[front].size(); ++i) {
      int node = v[front][i];
      if (check[node] == 0) {
        check[node] = front;
        q.push(node);
      }
    }
    q.pop();
  }
  for (int i = 2; i <= N; ++i) {
    cout << check[i] << '\n';
  }
}