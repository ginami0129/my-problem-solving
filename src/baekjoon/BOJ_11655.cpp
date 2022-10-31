#include <iostream>
#define MAX 101
using namespace std;

int main(void) {
  char input[MAX] = {0};
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin.getline(input, MAX);
  for (int i = 0; input[i]; ++i) {
    if (input[i] >= 'a') {
      cout << static_cast<char>('a' + (input[i] - 'a' + 13) % ('z' - 'a' + 1));
    } else if (input[i] >= 'A') {
      cout << static_cast<char>('A' + (input[i] - 'A' + 13) % ('Z' - 'A' + 1));
    } else {
      cout << input[i];
    }
  }
  cout << '\n';
}