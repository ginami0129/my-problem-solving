#include <iostream>

using namespace std;

int main(void)
{
  int N, sum = 0;
  cin >> N;
  while (N)
  {
    sum += N;
    --N;
  }
  cout << sum << '\n';
}