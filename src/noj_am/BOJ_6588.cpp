#include <cmath>
#include <iostream>
#define MAX 1000001
using namespace std;

int main(void) {
  int N, i = 0;
  bool d[MAX] = {1, 1};
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  for (int i = 2; i < sqrt(MAX); ++i) {
    if (d[i] == false) {
      for (int j = i * i; j < MAX; j += i) {
        d[j] = true;
      }
    }
  }
  cin >> N;
  while (N) {
    for (i = 2; i <= N; ++i) {
      if (d[i] == false && d[N - i] == false) {
        break;
      }
    }
    if (i > N) {
      cout << "Goldbach's conjecture is wrong." << '\n';
    } else {
      cout << N << " = " << i << " + " << N - i << '\n';
    }
    cin >> N;
  }
}