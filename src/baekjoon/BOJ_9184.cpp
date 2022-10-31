#include <bits/stdc++.h>
using namespace std;

int d[21][21][21], a, b, c;

int w(int a, int b, int c) {
  int result = 0;
  if (a <= 0 || b <= 0 || c <= 0) {
    return 1;
  }
  if (a > 20 || b > 20 || c > 20) {
    a = b = c = 20;
  }
  if (d[a][b][c] == 0) {
    if (a < b && b < c) {
      d[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
    } else {
      d[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
    }
  }
  return d[a][b][c];
}

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  while (true) {
    cin >> a >> b >> c;
    if (a == -1 && b == -1 && c == -1) break;
    cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << '\n';
  }
}