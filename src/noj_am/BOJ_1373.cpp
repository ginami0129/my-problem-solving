#include <iostream>
using namespace std;

int main(void) {
  string result, temp = "";
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> temp;
  while ((result.size() + temp.size()) % 3) {
    result.push_back('0');
  }
  temp = result + temp;
  result.clear();
  for (int i = 0; i < temp.size(); i += 3) {
    result.push_back('0' + (temp[i] - '0') * 4 + (temp[i + 1] - '0') * 2 + temp[i + 2] - '0');
  }
  cout << result << '\n';
}