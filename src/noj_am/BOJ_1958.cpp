#include <bits/stdc++.h>
#define MAX 101
using namespace std;

string str[3];
int d[MAX][MAX][MAX];

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  for (int i = 0; i < 3; ++i) {
    cin >> str[i];
  }
  for (int i = 1; i <= str[0].size(); ++i) {
    for (int j = 1; j <= str[1].size(); ++j) {
      for (int k = 1; k <= str[2].size(); ++k) {
        if (str[0][i - 1] == str[1][j - 1] && str[1][j - 1] == str[2][k - 1]) {
          d[i][j][k] = d[i - 1][j - 1][k - 1] + 1;
        } else if (str[0][i - 1] == str[1][j - 1]) {
          d[i][j][k] = max(d[i - 1][j - 1][k], d[i][j][k - 1]);
        } else if (str[1][j - 1] == str[2][k - 1]) {
          d[i][j][k] = max(d[i][j - 1][k - 1], d[i - 1][j][k]);
        } else if (str[0][i - 1] == str[2][k - 1]) {
          d[i][j][k] = max(d[i - 1][j][k - 1], d[i][j - 1][k]);
        } else {
          d[i][j][k] = max(d[i - 1][j][k], max(d[i][j - 1][k], d[i][j][k - 1]));
        }
      }
    }
  }
  cout << d[str[0].size()][str[1].size()][str[2].size()] << '\n';
}