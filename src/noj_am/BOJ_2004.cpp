#include <iostream>
using namespace std;

int main(void) {
  int n, m;
  long long a = 0, b = 0, i;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m;
  for (i = 2; i <= n; i *= 2) {
    a += n / i - (n - m) / i - m / i;
  }
  for (i = 5; i <= n; i *= 5) {
    b += n / i - (n - m) / i - m / i;
  }
  cout << min(a, b) << '\n';
}