#include <iostream>
using namespace std;

int main(void) {
  int A, B, C;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> A >> B >> C;
  cout << (A + B) % C << '\n';
  cout << (A % C + B % C) % C << '\n';
  cout << A * B % C << '\n';
  cout << (A % C) * (B % C) % C << '\n';
}