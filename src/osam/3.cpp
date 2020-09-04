#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> grade, int max_diff) {
    int answer = 0;
    int number = 0;
    vector<int> d(10001, 0);
    for (int i = 0; i <grade.size(); ++i) {
        ++d[grade[i]];
    }
    for (int i = 1; i <= 10000-max_diff + 1; ++i) {
        number = 0;
        for (int j = i; j <= i + max_diff; ++j) {
            number += d[j];
        }
        answer = max(number, answer);
    }
    return answer;
}