#include <iostream>
#include <queue>
using namespace std;

int check[100001];
queue<int> q;
int N, K;

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> N >> K;
  q.push(N);
  check[N] = true;
  while (!q.empty()) {
    int cur = q.front();
    if (cur == K) {
      cout << check[cur] - 1 << '\n';
      return 0;
    }
    if (cur + 1 < 100001 && !check[cur + 1]) {
      q.push(cur + 1);
      check[cur + 1] = check[cur] + 1;
    }
    if (cur - 1 >= 0 && !check[cur - 1]) {
      q.push(cur - 1);
      check[cur - 1] = check[cur] + 1;
    }
    if (cur * 2 < 100001 && !check[cur * 2]) {
      q.push(cur * 2);
      check[cur * 2] = check[cur] + 1;
    }
    q.pop();
  }
}