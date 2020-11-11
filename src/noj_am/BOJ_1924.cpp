#include <iostream>
#include <string>
using namespace std;

int main(void)
{
  int date[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int x, y;
  string day[7] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
  cin >> x >> y;
  for (int i = 1; i < x; ++i)
  {
    date[i] += date[i - 1];
  }
  cout << day[(date[x - 1] + y) % 7] << '\n';
}