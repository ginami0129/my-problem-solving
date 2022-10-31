#include <iostream>
#include <queue>
#include <string>
#include <unordered_set>
#include <utility>

using namespace std;
int map[3][3];
queue<pair<int, int>> q;
unordered_set<int> flag;
int number, digit, count, target = 123456789;
int dx[4] = {0, 0, -1, 1}, dy[4] = {-1, 1, 0, 0};

int main(void) {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  for (int i = 0; i < 9; ++i) {
    cin >> digit;
    if (digit == 0) digit = 9;
    number = number * 10 + digit;
  }

  flag.insert(number);
  q.push(make_pair(number, 0));
  int nx, ny, x, y, idx, next;
  string map, temp;
  while (!q.empty()) {
    number = q.front().first, count = q.front().second;
    if (number == target) break;
    map = to_string(number);
    idx = map.find('9'), x = idx / 3, y = idx % 3;
    for (int i = 0; i < 4; ++i) {
      nx = x + dx[i], ny = y + dy[i];
      if (nx < 0 || ny < 0 || nx >= 3 || ny >= 3) continue;
      temp = map;
      swap(temp[idx], temp[3 * nx + ny]);
      next = stoi(temp);
      if (flag.find(next) == flag.end()) {
        flag.insert(next);
        q.push(make_pair(next, count + 1));
      }
    }
    q.pop();
  }
  cout << (number == target ? count : -1) << '\n';
  return 0;
}