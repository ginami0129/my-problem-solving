#include <iostream>
using namespace std;

int main(void)
{
  int N, sum = 0;
  char num;
  cin >> N;
  while (N)
  {
    cin >> num;
    sum += num - '0';
    --N;
  }
  cout << sum << '\n';
}