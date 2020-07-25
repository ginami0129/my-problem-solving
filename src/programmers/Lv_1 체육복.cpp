#include <string>
#include <vector>
#define MAX_SIZE 32

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    int d[MAX_SIZE] = {0, };
    for (int i = 0; i < MAX_SIZE; ++i) d[i] = 1;
    for (auto r : reserve) ++d[r];
    for (auto l : lost) --d[l];
    for (int i = 1; i <= n; ++i) {
      if (d[i] == 2) {
        if (d[i-1] == 0) {
          ++d[i-1];
        } else if (d[i+1] == 0) {
          ++d[i+1];
        }
        --d[i];
      }
    }
    for (int i = 1; i <= n; ++i) {
      if (d[i] > 0) ++answer;
    }
    return answer;
}