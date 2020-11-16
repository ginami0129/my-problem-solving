#include <iostream>
#define M 10007
using namespace std;

int main(void)
{
  int N, sum = 0;
  int d[1001][10] = {0};
  fill_n(d[1], 10, 1);
  cin >> N;
  for (int i = 2; i <= N; ++i)
  {
    for (int j = 0; j < 10; ++j)
    {
      for (int k = 0; k <= j; ++k)
      {
        d[i][j] += d[i - 1][k];
      }
      d[i][j] %= M;
    }
  }
  for (int i = 0; i < 10; ++i)
  {
    sum += d[N][i];
    sum %= M;
  }
  cout << sum << '\n';
}