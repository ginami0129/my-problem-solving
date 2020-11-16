#include <iostream>
using namespace std;

int main(void)
{
  int N;
  int d[10001] = {0};
  int a[10001] = {0};
  cin >> N;
  for (int i = 1; i <= N; ++i)
  {
    cin >> a[i];
  }
  d[1] = a[1];
  d[2] = d[1] + a[2];
  for (int i = 3; i <= N; ++i)
  {
    d[i] = max(d[i - 3] + a[i - 1] + a[i], d[i - 2] + a[i]);
    d[i] = max(d[i], d[i - 1]);
  }
  cout << d[N] << '\n';
}