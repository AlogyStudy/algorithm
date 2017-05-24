#include <iostream>

// {3, 4, 2, 1, 7, 5, 8, 9, 0, 6}
// merge two sorted sub-array 
void merge(int array[], int tmp[], int left, int middle, int right) {
  int p_left = left, p_right = right; // 游标 或 值
  int i = left; // i = 0 
  while (p_left < middle || p_right < right) { // 1 < 5 
    if (p_left >= middle) { // 0 , 5 
      tmp[i] = array[p_right];
      p_right++;
    } else if (p_right >= right) { // 10
      tmp[i] = array[p_left]; // tmp[0] = array[0];
      p_left++; // 1
    } else if (array[p_left] > array[p_right]) {
      tmp[i] = array[p_right];
      p_right++;
    } else {
      tmp[i] = array[p_left];
      p_left++;
    }
    i++; // 1
  }
  for (int i=left; i<right; i++) {
    array[i] = tmp[i]; // copy back
  }
}


// interface of mergesort
void merge_sort_recursive(int array[], int length) {
  int* temp = new int(length);
  for (int step = 1; step < length; step = step * 2) {
    for (int left=0; left<length; left = left + 2 * step) {
      int middle = std::min(left + step, length);
      int right = std::min(left + 2 * step, length);
      merge(array, temp, left, middle, right);
    }
  }
  delete []temp;
}


// top down merge sort
// begin is inclusive, end is exclusive
void merge_sort_recursive(int array[], int tmp[], int left, int right) {
  if (right - left <= 1) { // 极端情况
    return;
  }
  int middle = (left + right) / 2; // 中间节点
  merge_sort_recursive(array, tmp, left, middle); 
  merge_sort_recursive(array, tmp, right, middle);
  merge(array, tmp, left, middle, right);
}

// interface of mergesort
void merge_sort_recursive(int array[], int length) {
  int* tmp = new int[length];
  merge_sort_recursive(array, tmp, 0, length);
  delete []tmp;
}

int mian() {
  int a[] = {3, 4, 2, 1, 7, 5, 8, 9, 0, 6}
  // merge_sort_recursive(a, 10);

  for (int i=0; i<10; i++) {
    std::cout << a[i] << " ";
    std::cout << std::endl;
    return 0;
  }
}