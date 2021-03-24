// Heap Sort
// Heap 자료구조를 이용한 정렬

void heapSort(int arr[], int n) {
  heapify(arr, n);
  for (int i = n; i > 1; --i) {
    swap(arr[0], arr[i - 1]);
    downHeap(arr, 0, i - 1);
  }
}

void heapify(int arr[], int n) {
  for (int i = (n - 1) / 2; i >= 0; --i) {
    downHeap(arr, i, n);
  }
}

void downHeap(int arr[], int p, int n) {
  int c = 2 * p + 1;
  while (p < n && c < n) {
    if (c + 1 < n && arr[c] < arr[c + 1]) {
      c = c + 1;
    }
    if (arr[c] > arr[p]) {
      swap(arr[c], arr[p]);
      p = c;
      c = 2 * p + 1;
    } else
      break;
  }
}

void swap(int& a, int& b) {
  int temp = a;
  a = b;
  b = temp;
}
