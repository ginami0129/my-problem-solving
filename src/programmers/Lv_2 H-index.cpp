#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    sort(citations.begin(), citations.end(), greater<int>());
    int h = citations[0];
    int count = 0;
    while (h > count) {
        count = 0;
        for (int i = 0; i < citations.size(); ++i) {
            if (citations[i] >= h) {
                count += 1;
            }
        }
        --h;
    }
    return h;
}