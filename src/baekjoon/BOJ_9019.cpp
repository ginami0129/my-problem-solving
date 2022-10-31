#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
using namespace std;

int T;
int A, B, number;
string command;
queue<pair<string, int> > q;
bool flag[10000];

int main(void) {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  cin >> T;
  while (T--) {
    cin >> A >> B;
    flag[A] = true;
    q.push(make_pair("", A));
    int next;
    while (!q.empty()) {
      command = q.front().first;
      number = q.front().second;
      if (number == B) break;
      next = number * 2 % 10000;
      if (flag[next] == false) {
        flag[next] = true, q.push(make_pair(command + 'D', next));
      }
      next = (number - 1 + 10000) % 10000;
      if (flag[next] == false) {
        flag[next] = true, q.push(make_pair(command + 'S', next));
      }
      next = number % 1000 * 10 + number / 1000;
      if (flag[next] == false) {
        flag[next] = true, q.push(make_pair(command + 'L', next));
      }
      next = (number % 10) * 1000 + number / 10;
      if (flag[next] == false) {
        flag[next] = true, q.push(make_pair(command + 'R', next));
      }
      q.pop();
    }
    while (!q.empty()) q.pop();
    for (int i = 0; i < 10000; ++i) flag[i] = false;
    cout << command << '\n';
  }
  return 0;
}