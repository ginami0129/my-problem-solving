#include <iostream>
using namespace std;

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int A, B, C;
  cin >> A >> B >> C;
  A *= B * C;
  int count[10] = {0};
  while (A) {
    ++count[A % 10];
    A /= 10;
  }
  for (int i = 0; i < 10; ++i) {
    cout << count[i] << '\n';
  }
}