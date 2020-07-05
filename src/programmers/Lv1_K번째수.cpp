#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> sorted;
    for (auto command : commands) {
      sorted = array;
        sort(sorted.begin()+command[0]-1, sorted.begin()+command[1]);
        answer.push_back(sorted[command[2]+command[0]-2]);
    }
    return answer;
}