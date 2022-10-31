#include <iostream>
using namespace std;

int main(void) {
  long long A, B, C, D;
  int t1 = 1, t2 = 1;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> A >> B >> C >> D;
  while (B / t1 > 0) t1 *= 10;
  while (D / t2 > 0) t2 *= 10;
  A = A * t1 + B;
  C = C * t2 + D;
  cout << A + C << '\n';
}