#include <iostream>
using namespace std;

int main(void)
{
  int N;
  int d[1000001] = {-1};
  cin >> N;
  for (int i = 1; i <= N; ++i)
  {
    d[i] = d[i - 1] + 1;
    if (i % 2 == 0)
    {
      d[i] = min(d[i], d[i / 2] + 1);
    }
    if (i % 3 == 0)
    {
      d[i] = min(d[i], d[i / 3] + 1);
    }
  }
  cout << d[N] << '\n';
}