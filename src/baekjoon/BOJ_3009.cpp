#include <iostream>
#include <utility>
using namespace std;

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  pair<int, int> input;
  pair<int, int> result;
  while (cin >> input.first >> input.second) {
    result.first ^= input.first;
    result.second ^= input.second;
  }
  cout << result.first << ' ' << result.second << '\n';
}