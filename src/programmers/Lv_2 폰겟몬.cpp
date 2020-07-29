#include <vector>
#include <set>

using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    set<int> porketmon;
    for (auto i : nums) {
        porketmon.insert(i);
    }
    answer = min(nums.size()/2 , porketmon.size());
    return answer;
}