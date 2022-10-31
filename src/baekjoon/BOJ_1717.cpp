#include <bits/stdc++.h>
#define MAX 1000001
using namespace std;

int p[MAX], r[MAX], n, m;

int Find(int x) {
  if (p[x] == x) return x;
  return (p[x] = Find(p[x]));
}

void Union(int x, int y) {
  x = Find(x);
  y = Find(y);
  if (x == y) return;
  if (r[x] < r[y]) {
    p[x] = y;
  } else {
    p[y] = x;
    if (r[x] == r[y]) {
      r[x] = r[x] + 1;
    }
  }
}

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    p[i] = i;
    r[i] = 1;
  }
  while (m--) {
    int op, x, y;
    cin >> op >> x >> y;
    if (op) {
      cout << (Find(x) == Find(y) ? "YES" : "NO") << '\n';
    } else {
      Union(x, y);
    }
  }
}