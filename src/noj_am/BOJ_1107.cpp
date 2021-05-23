#include <bits/stdc++.h>
using namespace std;

int n, m, cnt, digit, ans;
bool d[10], flag;

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    cin >> digit, d[digit] = true;
  }
  ans = abs(n - 100);
  for (int i = n; i <= 2 * n + 100; ++i) {
    digit = i, flag = true, cnt = 0;
    do {
      if (d[digit % 10]) {
        flag = false;
        break;
      }
      digit /= 10, ++cnt;
    } while (digit);
    if (flag) {
      ans = min(ans, cnt + i - n);
      break;
    }
  }
  for (int i = n; i >= 0; --i) {
    digit = i, flag = true, cnt = 0;
    do {
      if (d[digit % 10]) {
        flag = false;
        break;
      }
      digit /= 10, ++cnt;
    } while (digit);
    if (flag) {
      ans = min(ans, cnt + n - i);
      break;
    }
  }
  cout << ans << '\n';
}