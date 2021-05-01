#include <bits/stdc++.h>
using namespace std;

int n, i, temp, sum;

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> n;
  temp = n;
  while (temp) {
    i++;
    temp /= 10;
  }
  for (i = n - i * 9; i < n; ++i) {
    sum = temp = i;
    while (temp) {
      sum += (temp % 10);
      temp /= 10;
    }
    if (sum == n) break;
  }

  cout << (i == n ? 0 : i) << '\n';
}