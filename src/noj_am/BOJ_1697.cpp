#include <iostream>
#include <queue>
using namespace std;

queue<int> q;
bool flag[100001];
int N, M;

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> N >> M;
  q.push(N);
  flag[N] = true;
  int r = 0;
  while (!q.empty()) {
    int size = q.size();
    while (size--) {
      int cur = q.front();
      if (cur == M) {
        cout << r << "\n";
        return 0;
      }
      if (cur - 1 >= 0 && !flag[cur - 1]) {
        q.push(cur - 1);
        flag[cur - 1] = true;
      }
      if (cur + 1 < 100001 && !flag[cur + 1]) {
        q.push(cur + 1);
        flag[cur + 1] = true;
      }
      if (cur * 2 < 100001 && !flag[cur * 2]) {
        q.push(cur * 2);
        flag[cur * 2] = true;
      }
      q.pop();
    }
    ++r;
  }
  cout << r << '\n';
}