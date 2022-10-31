#include <bits/stdc++.h>
using namespace std;

int n, last, cnt = 1;
vector<pair<int, int> > meeting;

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> n;
  for (int i = 0; i < n; ++i) {
    int start, end;
    cin >> start >> end;
    meeting.push_back({end, start});
  }
  sort(meeting.begin(), meeting.end());
  for (int i = 1; i < n; ++i) {
    if (meeting[last].first <= meeting[i].second) ++cnt, last = i;
  }
  cout << cnt << '\n';
}