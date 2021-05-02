#include <bits/stdc++.h>
using namespace std;

int n, cnt;
pair<int, int> d[50];

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> d[i].first >> d[i].second;
  }
  for (int i = 0; i < n; ++i) {
    cnt = 1;
    for (int j = 0; j < n; ++j) {
      if (d[i].first < d[j].first && d[i].second < d[j].second) {
        ++cnt;
      }
    }
    cout << cnt << ' ';
  }
}