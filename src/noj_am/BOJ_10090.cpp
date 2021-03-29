#include <iostream>
using namespace std;

int n, arr[100001], temp[100001];
long long cnt;
void merge(int start, int mid, int end) {
  int left = start, cur = start;
  int right = mid + 1;
  while (left <= mid && right <= end) {
    if (arr[left] <= arr[right]) {
      temp[cur++] = arr[left++];
    } else {
      temp[cur++] = arr[right++];
      cnt += (mid - left + 1);
    }
  }
  while (left <= mid) {
    temp[cur++] = arr[left++];
  }
  for (int i = start; i < cur; ++i) {
    arr[i] = temp[i];
  }
}

void mergeSort(int start, int end) {
  if (start < end) {
    int mid = (start + end) >> 1;
    mergeSort(start, mid);
    mergeSort(mid + 1, end);
    merge(start, mid, end);
  }
}

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }
  mergeSort(0, n - 1);
  cout << cnt << '\n';
}