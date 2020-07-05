#include <iostream>
#include <algorithm>
#define MAX_SIZE 1000
using namespace std;

int main(void) {
  int N, result = 0;
  int d[MAX_SIZE] = {0, };
  int A[MAX_SIZE] = {0, };
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
    for (int j = 0; j < i; ++j) {
      if (A[j] > A[i]) {
        d[i] = max(d[j] + 1, d[i]);
      }
    }
    result = max(result, d[i] + 1);
  }
  cout << result << '\n';
}