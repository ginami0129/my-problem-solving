#include <cmath>
#include <iostream>
#define MAX 100010
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
  long long d[MAX] = {0};
  int count = 0;
  while (N--) {
    int num;
    cin >> num;
    if (num > 0 || num < 0) {
      d[count] = num;
      int child = count;
      int parent = (child - 1) / 2;
      while (child > 0 && abs(d[parent]) >= abs(d[child])) {
        swap(d[parent], d[child]);
        if (abs(d[parent]) == abs(d[child]) && d[parent] > d[child]) {
          swap(d[parent], d[child]);
        }
        child = parent;
        parent = (child - 1) / 2;
      }
      ++count;
    } else if (count == 0) {
      cout << 0 << '\n';
    } else {
      cout << d[0] << '\n';
      d[0] = d[count - 1];
      count = count - 1;
      int parent = 0;
      while (parent < count && 2 * parent + 1 < count) {
        int child = 2 * parent + 1;
        if (child + 1 < count && abs(d[child]) >= abs(d[child + 1])) {
          if (abs(d[child]) == abs(d[child + 1]) && d[child] < d[child + 1]) {
            child = child;
          } else {
            child = child + 1;
          }
        }
        if (abs(d[child]) <= abs(d[parent])) {
          if (abs(d[child]) == abs(d[parent]) && d[child] > d[parent]) {
            parent = child;
          } else {
            swap(d[child], d[parent]);
            parent = child;
          }
        } else
          break;
      }
    }
  }
}