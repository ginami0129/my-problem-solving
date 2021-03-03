#include <iostream>
using namespace std;

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  int num[9] = {0};
  int max = 0;
  for (int i = 0; i < 9; ++i) {
    cin >> num[i];
    if (num[i] > num[max]) {
      max = i;
    }
  }
  cout << num[max] << '\n';
  cout << max + 1 << '\n';
}