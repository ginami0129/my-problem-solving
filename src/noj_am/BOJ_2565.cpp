#include <bits/stdc++.h>
#define MAX 100
using namespace std;

pair<int, int> p[MAX];
int n, ans, d[MAX];

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> p[i].first >> p[i].second;
  }
  sort(p, p + n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
      if (p[j].first < p[i].first && p[j].second < p[i].second) {
        d[i] = max(d[i], d[j] + 1);
      }
    }
    ans = max(ans, d[i] + 1);
  }
  cout << n - ans << '\n';
}