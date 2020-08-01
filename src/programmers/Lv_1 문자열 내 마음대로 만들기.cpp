#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    for (int i = 0; i < strings.size(); ++i) {
        strings[i] = strings[i].substr(n,1) + 
                     strings[i].substr(0, n) + 
                     strings[i].substr(n+1);
    }
    sort(strings.begin(), strings.end());
    for (int i = 0; i < strings.size(); ++i) {
        strings[i] = strings[i].substr(1, n) + 
                     strings[i].substr(0,1) + 
                     strings[i].substr(n+1);
        answer.push_back(strings[i]);
    }
    return answer;
}