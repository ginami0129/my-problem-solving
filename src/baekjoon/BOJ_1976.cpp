#include <bits/stdc++.h>
using namespace std;

int p[201], d[1000], N, M;

int find(int x) {
  if (x == p[x]) return x;
  return (p[x] = find(p[x]));
}

void link(int x, int y) {
  x = find(x);
  y = find(y);
  if (x != y) {
    p[y] = x;
  }
}

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> N >> M;
  for (int i = 1; i <= N; ++i) {
    p[i] = i;
  }
  bool y;
  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= N; ++j) {
      cin >> y;
      if (y) link(i, j);
    }
  }
  for (int i = 0; i < M; ++i) {
    cin >> d[i];
  }
  y = true;
  int parent = find(d[0]);
  for (int i = 1; i < M && y; ++i) {
    y = (parent == find(d[i]) ? true : false);
  }
  cout << (y ? "YES" : "NO") << '\n';
}
