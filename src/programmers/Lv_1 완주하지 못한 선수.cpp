#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer;
    unordered_multiset<string> people;
    for (auto person : participant) {
        people.insert(person);
    }
    for (auto person : completion) {
        people.erase(people.find(person));
    }
    answer = *people.begin();
    return answer;
}