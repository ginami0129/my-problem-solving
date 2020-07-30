#include <string>
#include <vector>
using namespace std;

int solution(vector<vector<int>> baseball)
{
  int answer = 0, strike = 0, ball = 0, count = 0;
  int index;
  string num;
  for (int i = 111; i <= 999; ++i) {
    num = to_string(i);
    if (num[0] == num[1] ||
        num[1] == num[2] ||
        num[0] == num[2] ||
        num[1] == '0' || num[2] == '0') continue;
      for (auto input : baseball) {
        strike = ball = 0;
        for (int i = 0; i < 3; ++i) {
          if (to_string(input[0]).find(num[i]) != string::npos) {
            index = to_string(input[0]).find(num[i]);
            if (index == i) {
              ++strike;
            } else {
              ++ball;
            }
          }
        }
        if (strike == input[1] && ball == input[2]) ++count;
      }
      if (count == baseball.size()) ++answer;
      count = 0;
  }
  return answer;
}