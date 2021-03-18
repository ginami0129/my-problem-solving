#include <cmath>
#include <iostream>
using namespace std;

int N, r, c;
int result = 0;

int solve(int x, int y, long long size) {
  if (x == r && y == c) return result;
  int d = size / 2;
  if (r < x + d && c < y + d) {
    solve(x, y, d);
  } else if (r < x + d && c >= y + d) {
    result += (size * size / 4);
    solve(x, y + d, d);
  } else if (r >= x + d && c < y + d) {
    result += (size * d);
    solve(x + d, y, d);
  } else if (r >= x + d && c >= y + d) {
    result += (size * size * 3 / 4);
    solve(x + d, y + d, d);
  }
  return result;
}

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  cin >> N >> r >> c;
  cout << solve(0, 0, pow(2, N)) << '\n';
}
