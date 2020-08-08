#include <iostream>
#define MAX_SIZE 10001
using namespace std;

int main(void) {
  int n, result = 0;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  while (n) {
    result += n;
    --n;
  }
  cout << result << '\n';
}