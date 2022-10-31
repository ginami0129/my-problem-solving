#include <cmath>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct cmp {
  bool operator()(int x, int y) {
    if (abs(x) == abs(y)) {
      return x > y;
    } else {
      return abs(x) > abs(y);
    }
  }
};
priority_queue<int, vector<int>, cmp> pq;
int N, x;

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> N;
  while (N--) {
    cin >> x;
    if (x != 0) {
      pq.push(x);
    } else if (pq.size() == 0) {
      cout << 0 << '\n';
    } else {
      cout << pq.top() << '\n';
      pq.pop();
    }
  }
}