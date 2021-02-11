#include <iostream>
#define MAX 1000001
using namespace std;

int _lower_bound(int A[], int start, int end, int target) {
  int mid;
  while (start < end) {
    mid = (start + end) / 2;
    if (target <= A[mid]) {
      end = mid;
    } else {
      start = mid + 1;
    }
  }
  return start;
}

int main(void) {
  int A[MAX] = {0};
  int d[MAX] = {0};
  int N, index, end = 0;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
    if (d[end] < A[i]) {
      d[end + 1] = A[i];
      end++;
    } else {
      index = _lower_bound(d, 0, end, A[i]);
      d[index] = A[i];
    }
  }
  cout << end << '\n';
}