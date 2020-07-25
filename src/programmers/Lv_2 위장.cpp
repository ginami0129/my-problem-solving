#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, int> count;
    for (auto cloth : clothes) {
        ++count[cloth[1]];
    }
    for (auto i : count) {
        answer *= (i.second+1);
    }
    return answer-1;
}