#include <iostream>
#include <vector>

using namespace std;

int main(void) {
  vector<double> grade(12, 0);
  for (int i = 0; i < 12; ++i) {
    cin >> grade[i];
  }
  sort(grade.begin(), grade.end());
  for (int i = 2; i < 11; ++i) {
    grade[i] += grade[i-1];
  }
  cout.precision(1);
  cout << fixed << grade[10] / 10 << endl;
}