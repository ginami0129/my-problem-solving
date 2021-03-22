#include <cmath>
#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<int, int> check;
int A, P, temp;
int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> A >> P;
  for (int i = 1; !check[A]; ++i) {
    check[A] = i;
    temp = 0;
    while (A) {
      temp += pow(A % 10, P);
      A /= 10;
    }
    A = temp;
  }
  cout << check[A] - 1 << '\n';
}