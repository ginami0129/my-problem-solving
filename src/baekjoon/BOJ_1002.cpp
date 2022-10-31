#include <cmath>
#include <iostream>
using namespace std;

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int T;
  cin >> T;
  int x1, x2, y1, y2, r1, r2;
  while (T--) {
    cin >> x1 >> y1 >> r1;
    cin >> x2 >> y2 >> r2;
    int d = pow(x2 - x1, 2) + pow(y2 - y1, 2);
    int sum = pow(r1 + r2, 2);
    int diff = pow(r2 - r1, 2);
    if (d == 0 && r1 == r2) {
      cout << -1;
    } else if (d < diff || sum < d) {
      cout << 0;
    } else if (d == diff || d == sum) {
      cout << 1;
    } else {
      cout << 2;
    }
    cout << '\n';
  }
}