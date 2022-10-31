#include <bits/stdc++.h>
#define MAX 1000000
using namespace std;

int N, M, arr[MAX];
long long low, high;

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> N >> M;
  for (int i = 0; i < N; ++i) {
    cin >> arr[i];
  }

  high = 2000000000;
  while (low <= high) {
    long long target = 0;
    long long mid = (low + high) / 2;
    for (int i = 0; i < N; ++i) {
      target += (arr[i] < mid ? 0 : arr[i] - mid);
    }
    if (target < M) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  cout << high << '\n';
}