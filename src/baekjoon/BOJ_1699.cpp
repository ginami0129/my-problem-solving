// 1699 제곱수의 합
#include <bits/stdc++.h>
#define MAX 100001
using namespace std;

int n, d[MAX];

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> n;
  for (int i = 1; i <= n; ++i) {
    d[i] = i;
    for (int j = 2; j * j <= i; ++j) {
      d[i] = min(d[i], 1 + d[i - j * j]);
    }
  }
  cout << d[n] << '\n';
}