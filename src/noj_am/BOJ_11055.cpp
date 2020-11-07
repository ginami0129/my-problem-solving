#include <iostream>
#include <algorithm>
#define MAX_SIZE 1001
using namespace std;

int main(void) {
  int N, temp, result = 0;
  int A[MAX_SIZE] = {0, };
  int d[MAX_SIZE] = {0, };
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N;
  for (int i = 1; i <= N; ++i) {
    cin >> A[i];
    temp = 0;
    for (int j = 0; j < i; ++j) {
      if (A[j] < A[i])
        temp = max(temp, d[j]);
    }
    d[i] = A[i] + temp;
    result = max(result, d[i]);
  }
  cout << result << '\n';
}