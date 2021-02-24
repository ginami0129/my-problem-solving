#include <iostream>
#define MAX 101
using namespace std;

int main(void) {
  char input[MAX] = {0};
  int d[26] = {0};
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  fill_n(d, 26, -1);
  cin >> input;
  for (int i = 0; input[i]; ++i) {
    if (d[input[i] - 'a'] == -1) {
      d[input[i] - 'a'] = i;
    }
  }
  for (int i = 0; i < 26; ++i) {
    cout << d[i] << ' ';
  }
}