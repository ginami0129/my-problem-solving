#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
  vector<int> digits;
  int N;
  cin >> N;
  while(N) {
    digits.push_back(N % 10);
    N /= 10;
  }
  sort(digits.begin(), digits.end(), greater<int>());
  for (auto digit : digits) {
    cout << digit;
  }
}