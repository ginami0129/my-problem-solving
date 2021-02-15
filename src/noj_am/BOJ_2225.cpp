#include <iostream>
#define MAX 201
#define OUTPUT 1000000000
using namespace std;

int main(void) {
  int N, K;
  int d[MAX][MAX] = {0};
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N >> K;
  for (int i = 1; i <= K; ++i) {
    d[i][0] = 1;
    for (int j = 1; j <= N; ++j) {
      d[i][j] = (d[i - 1][j] + d[i][j - 1]) % OUTPUT;
    }
  }
  cout << d[K][N] << '\n';
}