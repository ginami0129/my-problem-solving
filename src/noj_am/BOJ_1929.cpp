#include <cmath>
#include <iostream>
#define MAX 1000001
using namespace std;

int main(void) {
  int M, N;
  bool d[MAX] = {
      1,
      1,
  };
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> M >> N;
  for (int i = 2; i < sqrt(N) + 1; ++i) {
    if (d[i] == false) {
      for (int j = i * i; j <= N; j += i) {
        d[j] = true;
      }
    }
  }
  for (int i = M; i <= N; ++i) {
    if (d[i] == false) {
      cout << i << '\n';
    }
  }
}