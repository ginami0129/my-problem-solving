#include <iostream>
using namespace std;

int fibo(int n) {
  if (n <= 1) return n;
  return fibo(n-1) + fibo(n-2);
}

int main(void) {
  int n;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  cout << fibo(n) << '\n';
}