#include <bits/stdc++.h>
using namespace std;

int n, k;

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  
  cin >> n >> k;
  int low = 1, high = k;
  while (low <= high) {
    int mid = (low + high) / 2;
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
      cnt += min(n, mid / i);
    }
    if (cnt >= k) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  cout << low << '\n';
}