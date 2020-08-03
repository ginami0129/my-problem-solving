#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    vector<vector<int>> cache(triangle.size()+1, vector<int>(triangle.size()+1, 0));
    for (int i = 1; i <= triangle.size(); ++i) {
      for (int j = 1; j <= i; ++j) {
        cache[i][j] = max(cache[i-1][j], cache[i-1][j-1]);
        cache[i][j] += triangle[i-1][j-1];
        answer = max(cache[i][j], answer);
      }
    }
    return answer;
}