#include <iostream>
#include <stack>
#include <string>
using namespace std;

int Calculate(const string & input);

int main(void) {
  string input;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> input;
  cout << Calculate(input) << '\n';
}

int Calculate(const string & input) {
  int result = 0;
  int temp = 0;
  stack<char> check;
  if (input.size() == 0) {
    return 1;
  } else if (input == "()") {
    return 2;
  } else if (input == "[]") {
    return 3;
  }
  for (int i = 0; i < input.size(); ++i) {
    if (input[i] == '(' || input[i] == '[') {
      check.push(input[i]);
    } else if (check.size() == 0) {
      return 0;
    } else if(input[i] == ')' && check.top() == '(') {
      check.pop();
    } else if (input[i] == ']' && check.top() == '[') {
      check.pop();
    }
    if (check.empty() == true) {
      if (input[temp] == '(' && input[i] == ')') {
        result += 2 * Calculate(input.substr(temp+1, i-temp-1));
      } else if (input[temp] == '[' && input[i] == ']') {
        result += 3 * Calculate(input.substr(temp+1, i-temp-1));
      }
      temp = i + 1;
    }
  }
  return (check.empty() ? result : 0);
}


// #include <iostream>
// #include <sstream>
// #include <string>
// using namespace std;

// int main(void) {
//   string str;
//   stringstream ss;
//   getline(cin, str);
//   ss.str(str);
//   while (ss >> str) {
//     cout << str << endl;
//   }
// }

// #include <iostream>
// #include <cstring>

// using namespace std;

// int main(void) {
//   char str[30];
//   cin.getline(str, 30);
//   char* tocken = strtok(str, " ");
//   while (tocken != NULL) {
//     cout << tocken << endl;
//     tocken = strtok(NULL, " ");
//   }
// }