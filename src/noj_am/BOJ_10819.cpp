#include <bits/stdc++.h>
#define MAX 8
using namespace std;

int arr[MAX], n, ans;

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }
  sort(arr, arr + n);
  while (next_permutation(arr, arr + n)) {
    int sum = 0;
    for (int i = 1; i < n; ++i) {
      sum += abs(arr[i] - arr[i - 1]);
    }
    ans = max(ans, sum);
  }
  cout << ans << '\n';
}