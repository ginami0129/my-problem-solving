#include <bits/stdc++.h>
#define MAX 101
using namespace std;

int n, m;
string d[MAX][MAX];

string add(string a, string b) {
  long long sum = 0;
  string result = "";
  while (!a.empty() || !b.empty() || sum) {
    if (!a.empty()) {
      sum += a.back() - '0';
      a.pop_back();
    }
    if (!b.empty()) {
      sum += b.back() - '0';
      b.pop_back();
    }
    result.push_back((sum % 10) + '0');
    sum /= 10;
  }
  reverse(result.begin(), result.end());
  return result;
}

string c(int n, int r) {
  if (n == r || r == 0) return "1";
  if (d[n][r] == "") {
    d[n][r] = add(c(n - 1, r), c(n - 1, r - 1));
  }
  return d[n][r];
}

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> n >> m;
  cout << c(n, m) << '\n';
}