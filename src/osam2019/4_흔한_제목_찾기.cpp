#include <iostream>
#include <vector>
using namespace std;

int main(void) {
  int N, Q;
  int start, end;
  char temp;
  char answer;
  int max_count = 0;
  int count = 0;
  vector<int> number('Z'-'A'+2, 0);
  cin >> N >> Q;
  while (N) {
    cin >> temp;
    ++number[temp-'A'+1];
    --N;
  }
  for (int i = 1; i < number.size(); ++i) {
    number[i] += number[i-1];
  }
  while (Q) {
    cin >> start >> end;
    for (int i = 1; i < number.size(); ++i) {
      if (number[i-1] + 1 > number[i]) continue;

      if (number[i-1] + 1 <= start && number[i] <= end ) {
        count = number[i] - start + 1;
      } else if (start <= number[i-1] + 1 && number[i] <= end) {
        count = number[i] - number[i-1];
      } else if ( number[i-1] + 1 <= end && number[i] >= end) {
        count = end - number[i-1];
      }

      if (max_count < count) {
        max_count = count;
        answer = i - 1 + 'A';
      }

    }
    cout << answer << '\n';
    max_count = 0;
    --Q;
  }
}