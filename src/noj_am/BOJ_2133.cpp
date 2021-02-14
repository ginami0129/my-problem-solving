#include <cmath>
#include <iostream>
#define MAX 31
using namespace std;

int main(void) {
  int N;
  int d[MAX] = {1};
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N;
  for (int i = 2; i <= N; i += 2) {
    d[i] = d[i - 2] * 3;
    for (int j = 0; j <= i - 4; j += 2) {
      d[i] += d[j] * 2;
    }
  }
  cout << d[N] << '\n';
}