#include <iostream>
#include <stack>
#define MAX 1000000
using namespace std;

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int N;
  int A[MAX] = {0};
  int r[MAX] = {0};
  stack<int> s;
  cin >> N;
  fill_n(r, N, -1);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  for (int i = 0; i < N; ++i) {
    if (s.empty() || A[s.top()] >= A[i]) {
      s.push(i);
    } else {
      while (!s.empty() && A[s.top()] < A[i]) {
        r[s.top()] = A[i];
        s.pop();
      }
      s.push(i);
    }
  }
  for (int i = 0; i < N; ++i) {
    cout << r[i] << ' ';
  }
  cout << '\n';
}