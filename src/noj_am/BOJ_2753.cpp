#include <iostream>
using namespace std;

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int year;
  cin >> year;
  cout << ((year % 4 == 0 && year % 100 > 0) || year % 400 == 0 ? 1 : 0) << '\n';
}