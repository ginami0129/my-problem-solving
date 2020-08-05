#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool dfs(vector<vector<string>> tickets, string start, int cnt, vector<bool> cache, vector<string> &answer) {
  answer.push_back(start);
  if(tickets.size() == cnt) return true;
  bool flag = false;
  for (int i = 0; i < tickets.size(); ++i) {
    if (tickets[i][0] == answer.back() && cache[i] == false) {
      cache[i] = true;
      flag = dfs(tickets, tickets[i][1], cnt+1, cache, answer);
      if (flag) return true;
      cache[i] = false;
    }
  }
  answer.pop_back();
  return false;
}
vector<string> solution(vector<vector<string>> tickets) {
  vector<string> answer;
  vector<bool> cache(tickets.size(), false);
  sort(tickets.begin(), tickets.end());
  dfs(tickets, "ICN", 0, cache, answer);
  return answer;
}