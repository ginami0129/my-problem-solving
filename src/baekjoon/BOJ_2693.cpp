#include <bits/stdc++.h>
using namespace std;

int A[10], T;

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> T;
  while (T--) {
    for (int i = 0; i < 10; ++i) {
      cin >> A[i];
    }
    sort(A, A + 10);
    cout << A[7] << '\n';
  }
}