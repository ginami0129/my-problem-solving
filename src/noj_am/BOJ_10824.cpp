#include <iostream>
#include <string>
using namespace std;

int main(void) {
  string A, B, C, D;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> A >> B >> C >> D;
  cout << stoll(A + B) + stoll(C + D) << '\n';
}