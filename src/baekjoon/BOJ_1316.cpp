#include <iostream>
#define MAX 101
#define SIZE 26
using namespace std;

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;
  int d[SIZE] = {0};
  char str[MAX] = {0};
  int result = N;
  while (N--) {
    cin >> str;
    fill_n(d, SIZE, -1);
    for (int i = 0; str[i]; ++i) {
      int c = str[i] - 'a';
      if (d[c] == -1 || i - d[c] == 1) {
        d[c] = i;
      } else {
        --result;
        break;
      }
    }
  }
  cout << result << '\n';
}
