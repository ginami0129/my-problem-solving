#include <iostream>
#include <stack>
using namespace std;

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;
  int A[N] = {0};
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  stack<int> s;
  int ans[N];
  fill_n(ans, N, -1);
  for (int i = 0; i < N; ++i) {
    while (!s.empty() && A[s.top()] < A[i]) {
      ans[s.top()] = A[i];
      s.pop();
    }
    s.push(i);
  }
  for (int i = 0; i < N; ++i) {
    cout << ans[i] << ' ';
  }
  cout << '\n';
}