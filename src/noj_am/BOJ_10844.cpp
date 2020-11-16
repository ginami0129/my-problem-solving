#include <iostream>
#define M 1000000000
using namespace std;

int main(void)
{
  int N, sum = 0;
  int d[101][10] = {0};
  cin >> N;
  fill_n(d[1] + 1, 9, 1);
  for (int i = 2; i <= N; ++i)
  {
    for (int j = 0; j < 10; ++j)
    {
      if (j >= 1)
      {
        d[i][j] += d[i - 1][j - 1];
      }
      if (j <= 8)
      {
        d[i][j] += d[i - 1][j + 1];
      }
      d[i][j] %= M;
    }
  }
  for (int i = 0; i < 10; ++i)
  {
    sum += d[N][i];
    sum %= M;
  }
  cout << sum << '\n';
}

// #include <iostream>
// #define M 1000000000
// using namespace std;

// int main(void)
// {
//   int N, sum = 0;
//   int D[10] = {0};
//   int D2[10] = {0};
//   cin >> N;
//   fill_n(D + 1, 9, 1);
//   while (--N)
//   {
//     for (int i = 0; i < 10; ++i)
//     {
//       D2[i] = 0;
//       if (i >= 1)
//       {
//         D2[i] += D[i - 1];
//       }
//       if (i <= 8)
//       {
//         D2[i] += D[i + 1];
//       }
//       D2[i] %= M;
//     }
//     for (int j = 0; j < 10; ++j)
//     {
//       D[j] = D2[j];
//     }
//   }
//   for (int i = 0; i < 10; ++i)
//   {
//     sum += D[i];
//     sum %= M;
//   }
//   cout << sum << '\n';
// }