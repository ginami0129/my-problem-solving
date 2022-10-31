#include <iostream>
using namespace std;

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  string str;
  cin >> str;
  int d[26] = {0};
  for (int i = 0; i < str.size(); ++i) {
    str[i] -= (str[i] >= 'a' ? 'a' : 'A');
    ++d[str[i]];
  }
  int max = 0;
  int count = 0;
  for (int i = 0; i < 26; ++i) {
    if (d[i] > d[max]) {
      max = i;
      count = 1;
    } else if (d[i] == d[max]) {
      ++count;
    }
  }
  if (count == 1) {
    cout << static_cast<char>(max + 'A') << '\n';
  } else {
    cout << '?' << '\n';
  }
}