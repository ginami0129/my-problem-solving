#include <iostream>
#include <algorithm>
#include <string>
#define MAX_SIZE 1001
using namespace std;

int main(void) {
  int i, j;
  string input, cmp, result;
  int d[MAX_SIZE][MAX_SIZE] = {0, };
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> input >> cmp;
  for (i = 1; i <= input.size(); ++i) {
    for (j = 1; j <= cmp.size(); ++j) {
      if (input[i-1] == cmp[j-1]) {
        d[i][j] = d[i-1][j-1] + 1;
      } else {
        d[i][j] = max(d[i-1][j], d[i][j-1]);
      }
    }
  }
  cout << d[--i][--j] << '\n';
  while (i > 0 && j > 0) {
    if (d[i][j] == d[i][j-1]) {
      --j;
    } else if (d[i][j] == d[i-1][j]) {
      --i;
    } else {
      result.push_back(input[i-1]);
      --i;
      --j;
    }
  }
  reverse(result.begin(), result.end());
  cout << result << '\n';
}