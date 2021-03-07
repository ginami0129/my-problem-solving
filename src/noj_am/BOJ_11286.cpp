#include <cmath>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct cmp {
  bool operator()(int a, int b) {
    if (abs(a) == abs(b)) {
      return a > b;
    } else {
      return abs(a) > abs(b);
    }
  }
};

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;
  priority_queue<int, vector<int>, cmp> q;
  while (N--) {
    int x;
    cin >> x;
    if (abs(x) > 0) {
      q.push(x);
    } else if (q.size() == 0) {
      cout << 0 << '\n';
    } else {
      cout << q.top() << '\n';
      q.pop();
    }
  }
}
