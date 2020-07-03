#include <iostream>
#define MAX_SIZE 1000001
#define MAX_OUTPUT 15746
using namespace std;

int main(void) {
  int N;
  int d[MAX_SIZE] = {1, 1, };
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N;
  for (int i = 2; i <= N; ++i) {
    d[i] = (d[i-1] + d[i-2]) % MAX_OUTPUT;
  }
  cout << d[N] << '\n';
}