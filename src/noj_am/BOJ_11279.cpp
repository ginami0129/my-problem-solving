#include <iostream>
#define MAX 100000
using namespace std;

void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;
  int d[MAX] = {0};
  int count = 0;

  while (N--) {
    int num;
    cin >> num;
    if (num == 0) {
      if (count == 0) {
        cout << 0 << '\n';
      } else {
        cout << d[0] << '\n';
        d[0] = d[count - 1];
        count = count - 1;
        int i = 0;
        while (i < count && 2 * i + 1 < count) {
          int cur = 2 * i + 1;
          if (cur + 1 < count && d[cur] < d[cur + 1]) {
            cur = cur + 1;
          }
          if (d[cur] > d[i]) {
            swap(d[cur], d[i]);
            i = cur;
          } else
            break;
        }
      }
    } else {
      d[count] = num;
      int i = count;
      int p = (i - 1) / 2;
      while (i > 0 && d[p] < d[i]) {
        swap(d[p], d[i]);
        i = p;
        p = (i - 1) / 2;
      }
      ++count;
    }
  }
}
