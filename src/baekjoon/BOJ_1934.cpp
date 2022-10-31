#include <iostream>
using namespace std;

int gcd(int a, int b) {
  return b ? gcd(b, a % b) : a;
}

int main(void) {
  int T;
  int A, B;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> T;
  while (T--) {
    cin >> A >> B;
    cout << A * B / gcd(A, B) << '\n';
  }
}