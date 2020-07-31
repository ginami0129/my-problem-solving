#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int solution(string numbers) {
    sort(numbers.begin(), numbers.end(), greater<char>());
    int answer = 0;
    int max_number = stoi(numbers);
    int digit = max_number;
    vector<bool> flag(max_number+1, true);
    vector<int> cache(10, 0);
    vector<int> temp(10, 0);
    while (digit) {
      ++temp[digit % 10];
      digit /= 10;
    }
    max_number = stoi(numbers);
    for (int i = 2; i <= sqrt(max_number); ++i) {
      if (flag[i] == false) continue;
      for (int j = 2; j < i; ++j) {
        if (i % j == 0) {
          flag[i] = false;
          break;
        }
      }
      if (flag[i] == true) {
        for (int k = 2; i*k <= max_number; ++k) {
          flag[i*k] = false;
        }
      }
    }
    for (int i = 2; i <= max_number; ++i) {
      if (flag[i] == false) continue;
      digit = i;
      cache = temp;
      while (digit) {
        --cache[digit % 10];
        if (cache[digit % 10] < 0) break;
        digit /= 10;
      }
      if (digit == 0) ++answer;
    }
    return answer;
}
