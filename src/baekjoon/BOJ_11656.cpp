#include <algorithm>
#include <iostream>
#include <string>
#define MAX 1000
using namespace std;

int main(void) {
  string input;
  string d[MAX];
  int n;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> input;
  for (int i = 0; i < input.size(); ++i) {
    d[i] = input.substr(i);
  }
  sort(d, d + input.size());
  for (int i = 0; i < input.size(); ++i) {
    cout << d[i] << '\n';
  }
}