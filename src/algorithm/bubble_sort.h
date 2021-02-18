// Bubble Sort
// 문자 그대로 마치 공기방울이 수면 위로 떠오르듯 가장 큰 레코드가 한 칸씩 한 칸씩 오른쪽으로 떠오르는 정렬
void Swap(int A[], int one, int two) {
  int temp = A[one];
  A[one] = A[two];
  A[two] = temp;
}

void BubbleSort(int A[], int size) {
  for (int j = 0; j < size; ++j) {
    for (int i = 1; i < size - j; ++i) {
      if (A[i - 1] > A[i]) {
        Swap(A, i, i - 1);
      }
    }
  }
}