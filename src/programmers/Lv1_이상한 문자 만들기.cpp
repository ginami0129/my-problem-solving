#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int j = 0;
    int diff = 'a' - 'A';
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == ' ') {
            j = 0;
            answer.push_back(s[i]);
        } else {
            if (j % 2 == 0 && 'a' <= s[i]) {
            answer.push_back(s[i] - diff);
            } else if (j % 2 == 1 && s[i] <= 'Z') {
                answer.push_back(s[i] + diff);
            } else {
                answer.push_back(s[i]);
            }
            ++j;
        }
    }
    return answer;
}