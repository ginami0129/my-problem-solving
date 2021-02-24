#include <iostream>
#define MAX 101
using namespace std;

int main(void) {
  int N;
  char input[MAX] = {0};
  int d[26] = {0};
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> input;
  for (int i = 0; input[i]; ++i) {
    ++d[input[i] - 'a'];
  }
  for (int i = 0; i < 26; ++i) {
    cout << d[i] << ' ';
  }
}