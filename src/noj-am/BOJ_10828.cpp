#include <stack>
#include <iostream>
#include <string>
using namespace std;

int main() {
  int N;
  stack<int> s;
  string command;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N;
  cin.get();
  while (N) {
    getline(cin, command);
    if (command.find("push") == 0) {
      s.push(stoi(command.substr(5)));
    } else if (command.find("pop") == 0) {
      if (s.empty()) {
        cout << -1 << '\n';
      } else {
        cout << s.top() << '\n';
        s.pop();
      }
    } else if (command.find("size") == 0) {
      cout << s.size() << '\n';
    } else if (command.find("empty") == 0) {
      cout << s.empty() << '\n';
    } else if (command.find("top") == 0) {
      if (s.empty()) {
        cout << -1 << '\n';
      } else {
        cout << s.top() << '\n';
      }
    }
    --N;
  }
}