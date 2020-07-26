#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    string num = "";
    unordered_map<string, int> count;
    for (auto number : phone_book) {
        for (int i = 0; i < number.size(); ++i) {
            num += number[i];
            ++count[num];
        }
        num = "";
    }
    for (auto number : phone_book) {
        if (count[number] > 1) {
            answer = false;
            break;
        }
    }
    return answer;
}