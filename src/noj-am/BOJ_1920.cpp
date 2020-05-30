#include <iostream>
#include <algorithm>
#define MAX_SIZE 100001
using namespace std;

bool IsExist(int A[], int start, int end, int key);

int main(void) {
  int N, M;
  int A[MAX_SIZE] = {0, };
  int key[MAX_SIZE] = {0, };
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  sort(A, A + N);
  cin >> M;
  for (int i = 0; i < M; ++i) {
    cin >> key[i];
    cout << IsExist(A, 0, N - 1, key[i]) << '\n';
  }
}

bool IsExist(int A[], int start, int end, int key) {
  long long mid = 0;
  while (start <= end) {
    mid = (start + end) / 2;
    if (A[mid] == key) {
      return true;
    } else if (A[mid] < key) {
      start = mid + 1;
    } else {
      end = mid - 1;
    }
  }
  return false;
}