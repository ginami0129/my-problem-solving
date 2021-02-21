// Quick Sort
// 파티션이란 어떤 수를 중심으로 나머지 수를 두 그룹으로 나누는 작업을 말한다.
// 파티션 과정을 수행 할 수 없을 때까지 파티션 과정을 수행한다.

void quickSort(int A[], int low, int high) {
  if (low < high) {
    int index = partition(A, low, high);
    quickSort(A, low, index - 1);
    quickSort(A, index + 1, high);
  }
}

int partition(int A[], int low, int high) {
  int &pivot = A[high];
  int j = low;
  for (int i = low; i < high; ++i) {
    if (A[i] < pivot) {
      swap(A[i], A[j]);
      ++j;
    }
  }
  swap(A[j], pivot);
  return j;
}

void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}
