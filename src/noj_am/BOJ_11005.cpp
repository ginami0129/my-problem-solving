#include <iostream>
#define MAX 32
using namespace std;

int main(void) {
  int N, B, i = 0;
  char d[MAX] = {0};
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N >> B;
  for (; N; ++i) {
    d[i] = N % B;
    d[i] += (d[i] < 10 ? '0' : 'A' - 10);
    N /= B;
  }
  for (--i; i >= 0; --i) {
    cout << d[i];
  }
  cout << '\n';
}