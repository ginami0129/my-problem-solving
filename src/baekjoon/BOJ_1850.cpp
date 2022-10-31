#include <iostream>
using namespace std;

int gcd(long long a, long long b) {
  return b ? gcd(b, a % b) : a;
}

int main(void) {
  long long A, B;
  int digit;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> A >> B;
  digit = gcd(A, B);
  while (digit--) {
    cout << 1;
  }
  cout << '\n';
}