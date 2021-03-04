#include <algorithm>
#include <iostream>
using namespace std;

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  string num;
  cin >> num;
  reverse(num.begin(), num.end());
  while (num.size() % 3) {
    num.push_back('0');
  }
  reverse(num.begin(), num.end());
  string result;
  for (int i = 0; i < num.size(); i += 3) {
    char c = '0';
    c += (num[i] - '0') * 4;
    c += (num[i + 1] - '0') * 2;
    c += (num[i + 2] - '0') * 1;
    result.push_back(c);
  }
  cout << result << '\n';
}