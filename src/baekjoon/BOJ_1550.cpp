#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

string str;
int result, digit = 1;

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> str;
  reverse(str.begin(), str.end());
  for (int i = 0; i < str.size(); ++i) {
    str[i] -= (str[i] >= 'A' ? 'A' - 10 : '0');
    result += digit * str[i];
    digit *= 16;
  }
  cout << result << '\n';
}