#include <iostream>
#include <algorithm>
#define MAX_SIZE 16
using namespace std;

int main(void) {
  int N;
  int T[MAX_SIZE] = {0, };
  int P[MAX_SIZE] = {0, };
  int temp = 0;
  int result = 0;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N;
  for (int i = 1; i <= N; ++i) {
    cin >> T[i] >> P[i];
  }
  for (int i = 1; i <= N; ++i) {
    if (i + T[i] > N+1) continue;
    temp = 0;
    for (int j = 1; j < i; ++j) {
      if (j + T[j] <= i) 
        temp = max(temp, P[j]);
    }
    P[i] += temp;
    result = max(result, P[i]);
  }
  cout << result << '\n';
}