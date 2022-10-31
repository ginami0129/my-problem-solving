#include <iostream>
#define MAX 1000
using namespace std;

int main(void) {
  int N, result = 0;
  int A[MAX] = {0};
  int d1[MAX] = {0};
  int d2[MAX] = {0};
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
    for (int j = 0; j < i; ++j) {
      if (A[j] < A[i]) {
        d1[i] = max(d1[i], d1[j]);
      }
    }
    ++d1[i];
  }
  for (int i = N - 1; i >= 0; --i) {
    for (int j = N - 1; j > i; --j) {
      if (A[j] < A[i]) {
        d2[i] = max(d2[i], d2[j]);
      }
    }
    ++d2[i];
    result = max(result, d1[i] + d2[i] - 1);
  }
  cout << result << '\n';
}