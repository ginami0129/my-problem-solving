#include <iostream>
#define MAX 101
using namespace std;

int gcd(int a, int b) {
  return b ? gcd(b, a % b) : a;
}

int main(void) {
  int t, n;
  long long sum = 0;
  int num[MAX] = {0};
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i < n; ++i) {
      cin >> num[i];
    }
    sum = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        sum += gcd(num[i], num[j]);
      }
    }
    cout << sum << '\n';
  }
}