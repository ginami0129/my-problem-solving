#include <iostream>
#define MAX_SIZE 31
using namespace std;

int main(void) {
  int c[MAX_SIZE][MAX_SIZE] = {0, };
  int T, N, M;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> T;
  for (int i = 1; i < MAX_SIZE; ++i) {
    c[i][0] = c[i][i] = 1;
    for (int j = 1; j < i ; ++j) {
      c[i][j] = c[i-1][j-1] + c[i-1][j];
    }
  }
  while (T) {
    cin >> N >> M;
    cout << c[M][N] << '\n';
    --T;
  }
}