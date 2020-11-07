#include <iostream>
#include <algorithm>
#define MAX_SIZE 301
using namespace std;

int main(void) {
  int n;
  int s[MAX_SIZE] = {0, }; 
  int d[MAX_SIZE] = {0, };
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> s[i];
  }
  d[1] = s[1];
  d[2] = s[1] + s[2];
  for (int i = 3; i <= n; ++i) {
    d[i] = max(d[i-2]+s[i], d[i-3]+s[i-1]+s[i]);
  }
  cout << d[n] << '\n';
}