#include <iostream>
#include <cmath>
using namespace std;

int main(void)
{
  int N;
  cin >> N;
  for (int i = N - 1; abs(i) < N; --i)
  {
    for (int j = 0; j < N + abs(i); ++j)
    {
      cout << ((N - 1 - abs(i) <= j) ? '*' : ' ');
    }
    cout << '\n';
  }
}