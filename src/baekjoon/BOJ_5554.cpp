#include <bits/stdc++.h>
using namespace std;

int num, total;

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  for (int i = 0; i < 4; ++i) {
    cin >> num;
    total += num;
  }
  cout << total / 60 << '\n';
  cout << total % 60 << '\n';
}