#include <iostream>

using namespace std;

int main(void)
{
  int N;
  cin >> N;
  for (int i = 1; i <= N; ++i)
  {
    for (int j = 0; j < N - i; ++j)
    {
      cout << ' ';
    }
    cout << '*';
    for (int k = 0; k < 2 * i - 3; ++k)
    {
      cout << (i == N ? '*' : ' ');
    }
    cout << (i == 1 ? "\n" : "*\n");
  }
}