#include <bits/stdc++.h>
using namespace std;

int n, m, k;

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> n >> m >> k;
  cout << k / m << ' ' << k % m << '\n';
}