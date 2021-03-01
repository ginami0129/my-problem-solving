#include <iostream>
using namespace std;

int main(void) {
  string input, result;
  string d[8] = {"000", "001", "010", "011", "100", "101", "110", "111"};
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> input;
  if (input == "0") {
    cout << 0 << '\n';
  } else {
    for (int i = 0; i < input.size(); ++i) {
      result.append(d[input[i] - '0']);
    }
    int index = result.find('1');
    cout << result.substr(index) << '\n';
  }
}