#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

vector<int> check(1000000, 0);
int A, P, ans;

int dfs(int A, int P) {
  check[A] = ++ans;
  int next = 0;
  while (A) {
    next += pow(A % 10, P);
    A /= 10;
  }
  if (check[next] == 0) {
    dfs(next, P);
  } else {
    ans = check[next];
  }
  return ans;
}

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> A >> P;
  cout << dfs(A, P) - 1 << '\n';
}