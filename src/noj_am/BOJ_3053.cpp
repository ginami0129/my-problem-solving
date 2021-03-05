#include <cmath>
#include <iostream>
using namespace std;

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  double r;
  cin >> r;
  cout << fixed;
  cout.precision(6);
  cout << M_PI * r * r << '\n';
  cout << 2 * r * r << '\n';
}