#include <bits/stdc++.h>
using namespace std;

int N, C, arr[200001];
long long low, high, diff;

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> N >> C;
  for (int i = 0; i < N; ++i) {
    cin >> arr[i];
  }
  sort(arr, arr + N);
  high = arr[N - 1] - arr[0];
  while (low <= high) {
    long long mid = (low + high) / 2;
    int cnt = 1;
    int cur = 0;
    for (int i = 1; i < N; ++i) {
      if (arr[i] - arr[cur] >= mid) {
        cnt++;
        cur = i;
      }
    }
    if (cnt >= C) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  cout << high << '\n';
}