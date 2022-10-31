#include <iostream>
#include <queue>
using namespace std;

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int N, K;
  cin >> N >> K;
  queue<int> q;
  for (int i = 1; i <= N; ++i) {
    q.push(i);
  }
  cout << '<';
  while (q.size() > 1) {
    int count = K;
    while (--count) {
      q.push(q.front());
      q.pop();
    }
    cout << q.front() << ", ";
    q.pop();
  }
  cout << q.front() << '>' << '\n';
}