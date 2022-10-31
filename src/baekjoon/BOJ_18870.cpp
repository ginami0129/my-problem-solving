#include <bits/stdc++.h>
using namespace std;

int n, num, cnt;
vector<pair<int, int> > arr;
vector<int> ans;

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> num;
    arr.push_back({num, i});
  }
  sort(arr.begin(), arr.end());
  ans.assign(n, 0);
  ans[arr[0].second] = 0;
  for (int i = 1; i < arr.size(); ++i) {
    if (arr[i - 1].first == arr[i].first) cnt++;
    ans[arr[i].second] = i - cnt;
  }
  for (int i = 0; i < ans.size(); ++i) {
    cout << ans[i] << ' ';
  }
}