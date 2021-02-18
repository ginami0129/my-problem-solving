// selection sort
// 가장 큰 것을 선택하여 가장 마지막 것과 스와핑하는 방식
void SelectionSort(int A[], int size) {
  int max;
  for (int i = size - 1; i > 0; --i) {
    max = i;
    for (int j = 0; j < i; ++j) {
      max = A[max] < A[j] ? j : max;
    }
    Swap(A, i, max);
  }
}

void Swap(int A[], int one, int two) {
  int temp = A[one];
  A[one] = A[two];
  A[two] = temp;
}