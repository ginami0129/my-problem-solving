#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    bool is_max = true;
    queue<int> printer;
    for (int i = 0; i < priorities.size(); ++i) {
        printer.push(i);
    }
    while (true) {
        for (int i = 1; i < priorities.size(); ++i) {
            if (priorities[i] > priorities.front()) {
                priorities.push_back(priorities.front());
                priorities.erase(priorities.begin());
                printer.push(printer.front());
                printer.pop();
                is_max = false;
                break;
            }
        }
        if (is_max) {
          ++answer;
          if (printer.front() == location) {
              break;
          }
          printer.pop();
          priorities.erase(priorities.begin());
        }
        is_max = true;
    }
    return answer;
}