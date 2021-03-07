#include <iostream>
#include <queue>
using namespace std;

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;
  int num;
  cin >> num;
  priority_queue<int> small;
  priority_queue<int, vector<int>, greater<int> > big;
  small.push(num);
  cout << small.top() << '\n';
  while (--N) {
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
    cout << min(small.top(), big.top()) << '\n';
  }
}