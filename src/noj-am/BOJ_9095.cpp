#include <iostream>
#define MAX_SIZE 11
using namespace std;

int main(void) {
  int d[MAX_SIZE] = {0, 1, 2, 4, };
  int T, N;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  for (int i = 4; i < MAX_SIZE; ++i) {
    d[i] = d[i-1] + d[i-2] + d[i-3];
  }
  cin >> T;
  while (T) {
    cin >> N;
    cout << d[N] << '\n';
    --T;
  }
}