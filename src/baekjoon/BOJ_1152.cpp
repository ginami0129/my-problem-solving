#include <iostream>
using namespace std;

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  string input;
  int count = 0;
  while (cin >> input) {
    ++count;
  }
  cout << count << '\n';
}