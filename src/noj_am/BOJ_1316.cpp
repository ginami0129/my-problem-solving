#include <iostream>
#define MAX 101
using namespace std;

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int N;
  char str[MAX] = {0};
  int d[26] = {0};
  cin >> N;
  int count = N;
  while (N--) {
    fill_n(d, 26, -1);
    cin >> str;
    for (int i = 0; str[i]; ++i) {
      char c = str[i] - 'a';
      if (d[c] == -1 || i - d[c] == 1) {
        d[c] = i;
      } else {
        --count;
        break;
      }
    }
  }
  cout << count << '\n';
}