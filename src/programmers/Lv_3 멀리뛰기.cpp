#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
    long long answer = 0;
    vector<vector<int>> cache(n+1, vector<int>(n+1, 0));
    cache[1][1] = cache[1][2] = 1;
    answer += cache[1][n];
    for (int i = 2; i <= n; ++i){
      for (int j = 1; j <= n; ++j) {
        cache[i][j] = (cache[i-1][j-1] + cache[i-1][j-2]) % 1234567;
      }
      answer = (answer + cache[i][n]) % 1234567;
    }
    return answer;
}