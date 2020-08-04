#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
  int answer = 0;
  vector<bool> cache(n, false);
  stack<int> r;
  bool flag = true;
  for (int i = 0; i < n; ++i) {
    if (cache[i]) continue;
    r.push(i);
    cache[i] = true;
    while(!r.empty()) {
      flag = true;
      for (int j = 0; j < n; ++j) {
        if (cache[j] == false && computers[r.top()][j] == 1) {
          r.push(j);
          cache[j] = true;
          flag = false;
          break;
        }
      }
      if (flag) r.pop();
    }
    ++answer;
  }
  return answer;
}