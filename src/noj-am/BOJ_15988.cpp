#include <iostream>
#define MAX_SIZE 1000001
using namespace std;

int main(void) {
  int d[MAX_SIZE] = {0, 1, 2, 4, };
  int T, N;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  for (int i = 4; i < MAX_SIZE; ++i) {
    for (int j = 1; j <= 3; j++) {
      d[i] = (d[i] + d[i-j]) % 1000000009;
    } 
  }
  cin >> T;
  while (T) {
    cin >> N;
    cout << d[N] << '\n';
    --T;
  }
}