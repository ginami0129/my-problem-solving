#include <iostream>

using namespace std;

int main(void)
{
  int A, B, T;
  cin >> T;
  while (T)
  {
    cin >> A >> B;
    cout << A + B << '\n';
    --T;
  }
}