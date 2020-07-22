#include <string>
#include <vector>
using namespace std;

string solution(string number, int k) {
    string answer = "";
    int start = 0;
    for (int i = number.size()-k; i >= 1; --i) {
      for (int j = start ; j < number.size() - i + 1; ++j) {
        if (number[start] < number[j]) start = j;
      }
      answer.push_back(number[start]);
      ++start;
    }
    return answer;
}