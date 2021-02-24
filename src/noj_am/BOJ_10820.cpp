#include <iostream>
#define MAX 101
using namespace std;

int main(void) {
  char input[MAX] = {0};
  int d[4] = {0};
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  while (cin.getline(input, MAX)) {
    for (int i = 0; input[i]; ++i) {
      if (input[i] >= 'a' && input[i] <= 'z') {
        ++d[0];
      } else if (input[i] >= 'A' && input[i] <= 'Z') {
        ++d[1];
      } else if (input[i] >= '0' && input[i] <= '9') {
        ++d[2];
      } else if (input[i] == ' ') {
        ++d[3];
      }
    }
    for (int i = 0; i < 4; ++i) {
      cout << d[i] << ' ';
      d[i] = 0;
    }
    cout << '\n';
  }
}