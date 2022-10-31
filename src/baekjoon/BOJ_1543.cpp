#include <bits/stdc++.h>
using namespace std;

string str, target;
int cnt;

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  getline(cin, str);
  getline(cin, target);
  if (str.size() >= target.size()) {
    for (int i = 0; i <= str.size() - target.size(); ++i) {
      int j = 0;
      for (; j < target.size(); ++j) {
        if (str[i + j] != target[j]) break;
      }
      if (j == target.size()) {
        cnt++, i += target.size() - 1;
      }
    }
  }
  cout << cnt << '\n';
}