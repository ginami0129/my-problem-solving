#include <iostream>
using namespace std;

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int num1, num2;
  cin >> num1 >> num2;
  cout << num1 * (num2 % 10) << '\n';
  cout << num1 * (num2 / 10 % 10) << '\n';
  cout << num1 * (num2 / 100) << '\n';
  cout << num1 * num2 << '\n';
}