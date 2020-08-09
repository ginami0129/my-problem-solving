#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
  int answer = 0;
  vector<int> range(1,1);
  for (int i = 0; i < stations.size(); ++i) {
    range.push_back(stations[i] - w - 1);
    range.push_back(stations[i] + w + 1);
  }
  range.push_back(n);
  for (int i = 0; i < range.size(); i+=2) {
    if (range[i] > range[i+1]) continue;
    answer += ceil((range[i+1] - range[i]+1) / static_cast<double>(2*w + 1));
  }
  return answer;
}