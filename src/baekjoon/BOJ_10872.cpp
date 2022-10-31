#include <iostream>
using namespace std;

int main(void) {
  int N, result = 1;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N;
  for (int i = 1; i <= N; ++i) {
    result *= i;
  }
  cout << result << '\n';
}