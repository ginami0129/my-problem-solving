#include <iostream>
#define MAX_SIZE 1001
using namespace std;

int main(void)
{
  int N;
  int d[MAX_SIZE] = {0, 1, 2};
  cin >> N;
  for (int i = 3; i <= N; ++i)
  {
    d[i] = (d[i - 1] + d[i - 2]) % 10007;
  }
  cout << d[N] << '\n';
}