#include <bits/stdc++.h>
#define MAX 10000000
using namespace std;

int n, num;
int cnt[2 * MAX + 1];

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> num;
    ++cnt[num + MAX];
  }
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> num;
    cout << cnt[num + MAX] << ' ';
  }
}