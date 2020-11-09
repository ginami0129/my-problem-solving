#include <iostream>
using namespace std;

int main(void)
{
  char input[101] = {0};
  cin.getline(input, 101);
  for (int i = 0; input[i]; ++i)
  {
    cout << input[i];
    if ((i + 1) % 10 == 0)
    {
      cout << '\n';
    }
  }
}