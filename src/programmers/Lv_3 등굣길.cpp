#include <string>
#include <vector>
using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    vector<vector<int>> d(n+1,vector<int>(m+1, 0));
    d[0][1] = 1;
    for (auto point : puddles) {
      d[point[1]][point[0]] = -1;
    }
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        d[i][j] = d[i][j] == -1 ?
                  0 : (d[i-1][j] + d[i][j-1]) %  1000000007;
      }
    }
    answer = d[n][m];
    return answer;
}