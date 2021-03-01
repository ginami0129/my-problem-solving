#include <iostream>
using namespace std;

int main(void) {
  int N;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N;
  cout << N / 5 + N / 25 + N / 125 << '\n';
}