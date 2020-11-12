#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
  int N;
  cin >> N;
  for (int i = N - 1; abs(i) < N; --i)
  {
    for (int j = 0; j < N; ++j)
    {
      cout << (j < abs(i) ? ' ' : '*');
    }
    cout << '\n';
  }
}