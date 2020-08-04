#include <iostream>
#include <string>
using namespace std;

int solution(string s) {
  int answer = 0;
  int left = 0, right = 0;
  for (int i = 0; i < s.size(); ++i) {
    left = i;
    right = i;
    while (left >= 0 && right < s.size()) {
      if (s[left] != s[right]) break;
      --left;
      ++right;
    }
    answer = max(answer , (right-i)*2 -1);
    left = i;
    right = i+1;
    while (left >= 0 && right < s.size()) {
      if (s[left] != s[right]) break;
      --left;
      ++right;
    }
    answer = max(answer , (right-1-i)*2);
  }
  return answer;
}