#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main(void) {
  queue<int> q;
  string command;
  int N;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N;
  // 공백 처리
  cin.get();
  while (N) {
    // 명령어 입력받기
    getline(cin, command);
    // 명령어에 따라 큐명령어 실행
    if (command.find("push") == 0) {
      // 명령어에서 숫자 추출
      q.push(stoi(command.substr(5)));
    } else if (command.find("pop") == 0) {
      if (q.empty()) {
        cout << -1 << '\n';
      } else {
        cout << q.front() << '\n';
        q.pop();
      }
    } else if (command.find("size") == 0) {
      cout << q.size() << '\n';
    } else if (command.find("empty") == 0) {
      cout << q.empty() << '\n';
    } else if (command.find("front") == 0) {
      cout << (q.empty() ? -1 : q.front()) << '\n';
    } else if (command.find("back") == 0) {
      cout << (q.empty() ? -1 : q.back()) << '\n';
    }
    --N;
  }
}