#include <iostream>
#define MAX 26
using namespace std;

int main(void) {
  int A, B, N, i, digit = 1, d = 0;
  int num[MAX] = {0};
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> A >> B >> N;
  for (i = 0; i < N; ++i) {
    cin >> num[i];
  }
  for (i = N - 1; i >= 0; --i) {
    d += digit * num[i];
    digit *= A;
  }
  for (i = 0; d; ++i) {
    num[i] = d % B;
    d /= B;
  }
  for (--i; i >= 0; --i) {
    cout << num[i] << ' ';
  }
}