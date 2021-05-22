#include <bits/stdc++.h>

using namespace std;
int earth, sun, moon, year;

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> earth >> sun >> moon;
  for (year = 0;; ++year) {
    if ((year % 15 + 1 == earth) && (year % 28 + 1 == sun) && (year % 19 + 1 == moon)) break;
  }
  cout << year + 1 << '\n';
}