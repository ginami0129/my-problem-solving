#include <bits/stdc++.h>
#define MAX 101
using namespace std;

int n, t;
long long d[MAX] = {0, 1, 1};

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  for (int i = 3; i < MAX; ++i) {
    d[i] = d[i - 2] + d[i - 3];
  }
  cin >> t;
  while (t--) {
    cin >> n;
    cout << d[n] << '\n';
  }
}