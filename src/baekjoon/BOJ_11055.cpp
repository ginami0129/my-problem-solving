#include <iostream>
#define MAX 1001
using namespace std;

int main(void) {
  int N, result = 0;
  int A[MAX] = {0};
  int d[MAX] = {0};
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
    for (int j = 0; j < i; ++j) {
      if (A[j] < A[i]) {
        d[i] = max(d[i], d[j]);
      }
    }
    d[i] += A[i];
    result = max(result, d[i]);
  }
  cout << result << '\n';
}