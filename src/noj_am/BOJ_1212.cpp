#include <iostream>
using namespace std;

int main(void) {
  string num;
  string result;
  string d[8] = {"000", "001", "010", "011", "100", "101", "110", "111"};
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> num;
  for (int i = 0; i < num.size(); ++i) {
    result.append(d[num[i] - '0']);
  }
  int i = 0;
  while (result[i] == '0') ++i;
  if (num == "0") {
    cout << 0 << '\n';
  } else {
    cout << result.substr(i) << '\n';
  }
}