#include <iostream>
using namespace std;

int main(void)
{
  char input[10001] = {0};
  cin.getline(input, 10001, EOF);
  cout << input;
}