#include <iostream>
using namespace std;

int main(void)
{
  int A, B, T;
  char ch = ',';
  cin >> T;
  while (T)
  {
    cin >> A >> ch >> B;
    cout << A + B << '\n';
    --T;
  }
}