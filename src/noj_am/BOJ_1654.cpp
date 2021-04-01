#include <bits/stdc++.h>
using namespace std;

int K, N, cnt;
int arr[10000];

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> K >> N;
  for (int i = 0; i < K; ++i) {
    cin >> arr[i];
  }
  long long start = 1;
  long long end = (1 << 31) - 1;
  while (start <= end) {
    long long mid = (start + end) / 2;
    cnt = 0;
    for (int i = 0; i < K; ++i) {
      cnt += arr[i] / mid;
    }
    if (cnt < N) {
      end = mid - 1;
    } else {
      start = mid + 1;
    }
  }
  cout << end << '\n';
}