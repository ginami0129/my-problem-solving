#include <iostream>
#define MAX_SIZE 1001
using namespace std;

int main(void) {
  int N, mxmm, result = 0;
  int A[MAX_SIZE] = {0};
  int d[MAX_SIZE] = {0};
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N;
  for (int i = 1; i <= N; ++i) {
    cin >> A[i];
    mxmm = 0;
    for (int j = 0; j < i; ++j) {
      if (A[j] < A[i]) {
        mxmm = max(mxmm, d[j]);
      }
    }
    d[i] = mxmm + 1;
    result = max(result, d[i]);
  }
  cout << result << '\n';
}