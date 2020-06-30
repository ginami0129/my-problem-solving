#include <iostream>
#include <algorithm>
#include <cmath>
#define MAX_SIZE 100001
using namespace std;

int main(void) {
  int N, temp;
  int d[MAX_SIZE] ={0, };
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N;
  for (int i = 1; i <= N; ++i) {
    d[i] = i;
    for (int j = sqrt(i); j > 0; --j) {
      d[i] = min(d[i], 1 + d[i - j*j]);
    }
  }
  cout << d[N] << '\n';
}