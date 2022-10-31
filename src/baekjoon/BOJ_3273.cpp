#include <bits/stdc++.h>
using namespace std;

int n, target, result;
vector<int> arr;

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> n;
  for (int i = 0; i < n; ++i) {
    int num;
    cin >> num;
    arr.push_back(num);
  }
  sort(arr.begin(), arr.end());
  cin >> target;
  int low = 0, high = arr.size() - 1;
  while (low < high) {
    int sum = arr[low] + arr[high];
    if (sum < target) {
      ++low;
    } else if (sum > target) {
      --high;
    } else {
      ++low;
      --high;
      ++result;
    }
  }
  cout << result << '\n';
}