#include <iostream>
#include <string>
#define MAX 5001
#define OUTPUT 1000000
using namespace std;

int main(void) {
  string input;
  int d[MAX] = {1};
  int num;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> input;
  d[1] = input[0] == '0' ? 0 : 1;
  for (int i = 2; i <= input.size(); ++i) {
    num = (input[i - 2] - '0') * 10 + input[i - 1] - '0';
    if (num >= 10 && num <= 26) {
      d[i] += d[i - 2];
    }
    num %= 10;
    if (num >= 1 && num <= 9) {
      d[i] += d[i - 1];
    }
    d[i] %= OUTPUT;
  }
  cout << d[input.size()] << '\n';
}