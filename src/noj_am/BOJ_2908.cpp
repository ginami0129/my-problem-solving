#include <iostream>
using namespace std;

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int A, B;
  cin >> A >> B;
  A = 100 * (A % 10) + (A / 10) % 10 * 10 + A / 100;
  B = 100 * (B % 10) + (B / 10) % 10 * 10 + B / 100;
  cout << (A > B ? A : B) << '\n';
}