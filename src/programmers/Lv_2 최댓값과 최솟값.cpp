#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

string solution(string s) {
    string answer = "";
    int num;
    vector<int> number;
    stringstream ss(s);
    while (ss >> num) {
        number.push_back(num);
    }
    sort(number.begin(), number.end());
    answer = to_string(number.front()) + " " + to_string(number.back());
    return answer;
}
