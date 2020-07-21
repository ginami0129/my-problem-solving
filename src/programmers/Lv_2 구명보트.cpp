#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int index = 0;
    sort(people.begin(), people.end());
    for (int i = people.size()-1; i >= index; --i) {
      if (people[index] + people[i] <= limit) ++index; 
      ++answer;
    }
    return answer;
}