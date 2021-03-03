#include <iostream>
using namespace std;

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int x, y;
  cin >> x >> y;
  if (x > 0) {
    cout << (y > 0 ? 1 : 4) << '\n';
  } else {
    cout << (y > 0 ? 2 : 3) << '\n';
  }
}