// Merge Sort
// 쉽게 정렬할 수 있는 크기의 리스트로 분할하고 정렬한 후 정렬된 부분 리스트들을 합쳐서 정렬된 하나의 리스트로 만드는 방법
#define MAX 1000000
int temp[MAX] = {0};

void MergeSort(int nums[], int low, int high) {
  if (low < high) {
    int mid = (low + high) / 2;
    MergeSort(nums, low, mid);
    MergeSort(nums, mid + 1, high);
    Merge(nums, low, mid, high);
  }
}

void Merge(int nums[], int low, int mid, int high) {
  int left = low;
  int right = mid + 1;
  int cur = low;

  while (left <= mid && right <= high) {
    if (nums[left] < nums[right]) {
      temp[cur] = nums[left];
      ++left;
    } else {
      temp[cur] = nums[right];
      ++right;
    }
    ++cur;
  }

  for (; left <= mid; ++left, ++cur) {
    temp[cur] = nums[left];
  }

  for (int i = low; i < cur; ++i) {
    nums[i] = temp[i];
  }
}
