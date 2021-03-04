#include <iostream>
#include <utility>
using namespace std;

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  pair<int, int> p1, p2, p3;
  cin >> p1.first >> p1.second;
  cin >> p2.first >> p2.second;
  cin >> p3.first >> p3.second;

  if (p1.first == p2.first) {
    cout << p3.first << ' ';
  } else if (p2.first == p3.first) {
    cout << p1.first << ' ';
  } else {
    cout << p2.first << ' ';
  }

  if (p1.second == p2.second) {
    cout << p3.second << ' ';
  } else if (p2.second == p3.second) {
    cout << p1.second << ' ';
  } else {
    cout << p2.second << ' ';
  }
}