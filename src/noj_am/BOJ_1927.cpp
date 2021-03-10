#include <iostream>
using namespace std;

int heap[100001];
int size, n, x, c, p;

void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

int main(void) {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  while (n--) {
    int x;
    cin >> x;
    if (x > 0) {
      heap[size++] = x;
      c = size - 1;
      p = (c - 1) / 2;
      while (c > 0 && heap[c] < heap[p]) {
        swap(heap[c], heap[p]);
        c = p;
        p = (c - 1) / 2;
      }
    } else if (size == 0) {
      cout << 0 << '\n';
    } else {
      cout << heap[0] << '\n';
      heap[0] = heap[--size];
      p = 0;
      c = 2 * p + 1;
      while (p < size && c < size) {
        if (c + 1 < size && heap[c] > heap[c + 1]) {
          c = c + 1;
        }
        if (heap[c] < heap[p]) {
          swap(heap[c], heap[p]);
          p = c;
          c = 2 * p + 1;
        } else
          break;
      }
    }
  }
}