#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, vector<int> tshirts) {
    int answer = 0;
    int index = 0;
    sort(people.begin(), people.end());
    sort(tshirts.begin(), tshirts.end(), greater<int>());
    for (int i = people.size()-1; i >= 0; --i) {
        for (int j = index; j < tshirts.size(); ++j) {
            if (tshirts[j] < people[i]) continue;
            index = ++j;
            ++answer;
            break;
        }
    }
    return answer;
}