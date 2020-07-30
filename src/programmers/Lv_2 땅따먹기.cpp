#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> land)
{
  int answer = 0;
  vector<vector<int>> map(land.size(), vector<int>(4,0));
  int temp = 0;
  for (int i = 0; i < 4; ++i) {
    map[0][i] = land[0][i];
  }
  for (int i = 1; i < land.size(); ++i) {
    for (int j = 0; j < 4; ++j) {
      for (int k = 0; k < 4; ++k) {
        if (k != j) map[i][j] = max(map[i][j], map[i-1][k]);
      }
      map[i][j] += land[i][j];
      answer = max(answer, map[i][j]);
    }
  }
  return answer;
}
