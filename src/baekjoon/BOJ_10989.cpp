#include <iostream>
#define MAX 10001
using namespace std;

int main(void) {
  int number, N;
  int d[MAX] = {0};
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N;
  while (N--) {
    cin >> number;
    ++d[number];
  }
  for (int i = 1; i < MAX; ++i) {
    while (d[i]--) {
      cout << i << '\n';
    }
  }
}