#include <iostream>
#include <algorithm>
#define MAX_SIZE 10001
using namespace std;

int main(void) {
  int n;
  int a[MAX_SIZE] = {0, }; 
  int d[MAX_SIZE] = {0, };
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  d[1] = a[1];
  d[2] = a[1] + a[2];
  for (int i = 3; i <= n; ++i) {
    d[i] = max(d[i-2]+a[i], d[i-3]+a[i-1]+a[i]);
    d[i] = max(d[i], d[i-1]);
  }
  cout << d[n] << '\n';
}