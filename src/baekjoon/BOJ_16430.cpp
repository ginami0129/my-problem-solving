#include <bits/stdc++.h>
using namespace std;

int a, b;

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> a >> b;
  cout << max(a, b) - min(a, b) << " " << max(a, b) << '\n';
}