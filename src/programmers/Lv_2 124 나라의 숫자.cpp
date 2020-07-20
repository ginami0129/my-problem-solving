#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    while (n) {
        answer = "412"[n%3] + answer;
        n = n%3 == 0 ? n/3 -1 : n/3;
    }
    return answer;
}