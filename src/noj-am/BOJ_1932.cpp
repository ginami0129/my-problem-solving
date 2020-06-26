#include <iostream>
#include <algorithm>
#define MAX_SIZE 501
using namespace std;

int main(void) {
  int d[MAX_SIZE][MAX_SIZE] = {0, };
  int n;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= i; j++) {
      cin >> d[i][j];
    } 
  }
  for (int i = n-1; i >= 0; --i) {
    for (int j = 0; j < i+1; ++j) {
      d[i][j] += max(d[i+1][j], d[i+1][j+1]);
    }
  }
  cout << d[0][0] << '\n';
}