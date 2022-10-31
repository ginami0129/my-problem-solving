#include <iostream>
using namespace std;

int main(void)
{
  int N, number, min_number = 1000000, max_number = -1000000;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N;
  while (N)
  {
    cin >> number;
    min_number = min(number, min_number);
    max_number = max(number, max_number);
    --N;
  }
  cout << min_number << " " << max_number << "\n";
}