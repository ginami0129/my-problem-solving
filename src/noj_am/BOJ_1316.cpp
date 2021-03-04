#include <iostream>
#define MAX 101
using namespace std;

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int N, count = 0;
  int d[26] = {0};
  char str[MAX] = {0};
  cin >> N;
  while (N--) {
    cin >> str;
    fill_n(d, 26, -1);
    for (int i = 0; str[i]; ++i) {
      int c = str[i] - 'a';
      if (d[c] == -1 || i - d[c] == 1) {
        d[c] = i;
      } else {
        --count;
        break;
      }
    }
    ++count;
  }
  cout << count << '\n';
}