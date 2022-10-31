#include <iostream>
using namespace std;

int main(void) {
  int A, B;
  cin >> A >> B;
  while(!cin.eof()) {
    cout << A + B << '\n';
    cin >> A >> B;
  }
}