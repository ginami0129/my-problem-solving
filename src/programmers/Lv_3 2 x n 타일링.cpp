#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> cache(60001, 1);
    for (int i = 2; i <= n; ++i) {
      cache[i] = (cache[i-1] + cache[i-2]) % 1000000007;
    }
    answer = cache[n];
    return answer;
}