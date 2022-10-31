#include <iostream>
using namespace std;

int main(void) {
  int A, B;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> A >> B;
  for (int i = min(A, B); i > 0; --i) {
    if (A % i == 0 && B % i == 0) {
      cout << i << '\n';
      break;
    }
  }
  for (int i = max(A, B);; ++i) {
    if (i % A == 0 && i % B == 0) {
      cout << i << '\n';
      break;
    }
  }
}