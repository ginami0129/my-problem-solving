#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> nums) {
  int answer = 0;
  int number = 0;
  bool flag = true;
  for (int i = 0; i < nums.size(); ++i) {
    for (int j = i+1; j < nums.size(); ++j) {
      for (int k = j+1; k < nums.size(); ++k) {
        number = nums[i] + nums[j] + nums[k];
        flag = true;
        for (int i = 2; i < number; ++i) {
          if (number % i == 0) {
            flag = false;
            break;
          }
        }
        if (flag == true) ++answer;
      }
    }
  }
  return answer;
}