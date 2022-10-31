#include <bits/stdc++.h>
#define MAX 500000
using namespace std;

int N, A[MAX], help[MAX];
long long result;

void merge(int start, int mid, int end) {
  int left = start, cur = start;
  int right = mid + 1;
  while (left <= mid && right <= end) {
    if (A[right] < A[left]) {
      help[cur++] = A[right++];
      result += (mid - left + 1);
    } else {
      help[cur++] = A[left++];
    }
  }
  while (left <= mid) {
    help[cur++] = A[left++];
  }
  for (int i = start; i < cur; ++i) {
    A[i] = help[i];
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

  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  mergeSort(0, N - 1);
  cout << result << '\n';
}