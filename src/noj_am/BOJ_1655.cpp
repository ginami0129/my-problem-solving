#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, num;
priority_queue<int> small;
priority_queue<int, vector<int>, greater<int> > big;

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  small.push(-100000);
  big.push(10000);
  cin >> N;
  while (N--) {
    cin >> num;
    if (small.top() < num) {
      big.push(num);
    } else {
      small.push(num);
    }
    if (small.size() - 1 > big.size()) {
      big.push(small.top());
      small.pop();
    } else if (small.size() < big.size()) {
      small.push(big.top());
      big.pop();
    }
    cout << small.top() << '\n';
  }
}