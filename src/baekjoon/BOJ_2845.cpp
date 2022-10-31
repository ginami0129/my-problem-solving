#include <bits/stdc++.h>
using namespace std;

int L, P, d[5];

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> L >> P;
  for (int i = 0; i < 5; ++i) {
    cin >> d[i];
  }
  for (int i = 0; i < 5; ++i) {
    cout << d[i] - L * P << ' ';
  }
}