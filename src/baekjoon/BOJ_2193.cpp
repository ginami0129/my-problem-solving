#include <iostream>
using namespace std;

int main(void)
{
  int N;
  int64_t d[91] = {0, 1, 1};
  cin >> N;
  for (int i = 3; i <= N; ++i)
  {
    d[i] = d[i - 1] + d[i - 2];
  }
  cout << d[N] << '\n';
}