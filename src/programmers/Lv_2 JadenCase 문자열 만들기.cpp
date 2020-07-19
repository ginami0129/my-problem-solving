#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    for (int i = 0; i < s.size(); ++i) {
        if (i == 0 || s[i-1] == ' ') {
            if (s[i] >= 'a' && s[i] <= 'z') s[i] ^= 32;
        } else if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] ^= 32;
        }
    }
    return s;
}