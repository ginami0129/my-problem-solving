#include <iostream>
#define MAX_SIZE 41
using namespace std;

int main(void) {
  int T, N;
  int fibo[MAX_SIZE] = {0, 1, };
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> T;
  for (int i = 2; i < MAX_SIZE; ++i) {
    fibo[i] = fibo[i-1] + fibo[i-2];
  }
  while (T) {
    cin >> N;
    if (N == 0) {
      cout << 1 << " " << 0 << '\n'; 
    } else {
      cout << fibo[N-1] << " " << fibo[N] << '\n';
    }
    --T;
  }
}