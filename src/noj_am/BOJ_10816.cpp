#include <bits/stdc++.h>
#define MAX 10000000
using namespace std;

int n, m, target, arr[MAX];

int lowerBound(int low, int high, int target) {
  int mid;
  while (low <= high) {
    mid = (low + high) / 2;
    if (arr[mid] >= target) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  return low;
}

int upperBound(int low, int high, int target) {
  int mid;
  while (low <= high) {
    mid = (low + high) / 2;
    if (target < arr[mid]) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  return low;
}

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }
  sort(arr, arr + n);
  cin >> m;
  for (int i = 0; i < m; ++i) {
    cin >> target;
    cout << upperBound(0, n - 1, target) - lowerBound(0, n - 1, target) << ' ';
  }
}