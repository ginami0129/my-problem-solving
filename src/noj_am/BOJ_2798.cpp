#include <bits/stdc++.h>
using namespace std;

int N, M, d[100], ans;

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> N >> M;
  for (int i = 0; i < N; ++i) {
    cin >> d[i];
  }
  for (int i = 0; i < N; ++i) {
    for (int j = i + 1; j < N; ++j) {
      for (int k = j + 1; k < N; ++k) {
        if (d[i] + d[j] + d[k] > M) continue;
        ans = max(ans, d[i] + d[j] + d[k]);
      }
    }
  }
  cout << ans << '\n';
}