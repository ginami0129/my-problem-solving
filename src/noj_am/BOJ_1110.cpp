#include <iostream>
using namespace std;

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int N, num, count = 0;
  cin >> N;
  num = N;
  do {
    num = (num % 10) * 10 + (num / 10 + num % 10) % 10;
    ++count;
  } while (N != num);
  cout << count << '\n';
}
