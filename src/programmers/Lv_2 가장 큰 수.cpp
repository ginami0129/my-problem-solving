#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(int a, int b) {
    string op1 = to_string(a);
    string op2 = to_string(b);
    a = stoi(op1 + op2);
    b = stoi(op2 + op1);
    return a > b;
}

string solution(vector<int> numbers) {
    string answer = "";
    sort(numbers.begin(), numbers.end(), cmp);
    for (int i = 0; i < numbers.size(); ++i) {
        answer += to_string(numbers[i]);
    }
    if (answer[0] == '0') answer = '0';
    return answer;
}