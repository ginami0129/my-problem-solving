#include <iostream>

using namespace std;

int main(void)
{
  int N, T;
  int d[11] = {0, 1, 2, 4};
  cin >> T;
  while (T--)
  {
    cin >> N;
    for (int i = 4; i <= N; ++i)
    {
      d[i] = d[i - 1] + d[i - 2] + d[i - 3];
    }
    cout << d[N] << '\n';
  }
}