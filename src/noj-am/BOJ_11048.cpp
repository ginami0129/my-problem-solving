#include <iostream>
#include <algorithm>
#define MAX_SIZE 1001
using namespace std;

int main(void) {
  int d[MAX_SIZE][MAX_SIZE] ={0, };
  int N, M;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N >> M;
  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= M; ++j) {
      cin >> d[i][j];
      d[i][j] += max(max(d[i-1][j], d[i][j-1]), d[i-1][j-1]);
    }
  }
  cout << d[N][M] << '\n';
}