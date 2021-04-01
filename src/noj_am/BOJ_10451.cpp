#include <bits/stdc++.h>
using namespace std;

int T, N, cnt;
vector<int> v(1001, 0);
vector<bool> check(1001, false);

void dfs(int V) {
  check[V] = true;
  int next = v[V];
  if (check[next] == false) {
    dfs(next);
  } else if (check[next] == true) {
    ++cnt;
  }
}

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> T;
  while (T--) {
    cin >> N;
    cnt = 0;
    check.assign(N + 1, false);
    for (int i = 1; i <= N; ++i) {
      cin >> v[i];
    }
    for (int i = 1; i <= N; ++i) {
      if (check[i] == true) continue;
      dfs(i);
    }
    cout << cnt << '\n';
  }
}