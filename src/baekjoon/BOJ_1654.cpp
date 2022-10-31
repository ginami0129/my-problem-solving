#include <bits/stdc++.h>
#define MAX 10000
using namespace std;

int k, n, arr[MAX];

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> k >> n;
  for (int i = 0; i < k; ++i) {
    cin >> arr[i];
  }
  
  long long low = 1;
  int high = INT_MAX;

  while (low <= high) {
    long long mid = (low + high) / 2;
    int sum = 0;
    for (int i = 0; i < k; ++i) {
      sum += arr[i] / mid;
    }
    if (sum < n) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  cout << high << '\n';
}