// Insertion Sort
// 우리가 화투가 카드패를 정렬할 때 무심코 적용하는 방법이다.
void InsertionSort(int A[], int size) {
  for (int i = 1; i < size; ++i) {
    int temp = A[i];
    int j = i;
    while (j > 0 && (A[j - 1] > temp)) {
      A[j] = A[j - 1];
      --j;
    }
    A[j] = temp;
  }
}