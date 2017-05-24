#include <iostream>
#include <utility>

using namespace std;

// end in inclusive
void quick_sort(int a[], int begin, int end) {
  if (begin >= end) { // 递归算法 会前置判断 递归出口， 符合结束条件.
    return;
  }
  int left = begin, right = end;
  int pivot_value = a[left]; // 轴心
  while(left < right) {
    if (a[left+1] < pivot_value) {
      a[left] = a[left+1];
      left++;
    } else {
      swap(a[left+1], a[right]);
      right--;
    }
  }
  a[left] = pivot_value;
  quick_sort(a, begin, left-1);
  quick_sort(a, left+1, end);
}

void quick_sort_wiki(int a[], int begin, int end) {
  if (begin >= end) {
    return;
  }
  int pivot_value = begin;
  int pivot_value = a[pivot_value];
  for (int k=begin+1; k<=end; k++) {
    if (a[k] < pivot_value) {
      pivot_value++;
      swap(a[begin], a[pivot_value]);
    }
  }
  swap(a[begin], a[pivot_value]);  
  quick_sort_wiki(a, begin, pivot_value-1);
  quick_sort_wiki(a, pivot_value+1, end);
}

int main() {
  int a[] = {3, 4, 2, 1, 7, 5, 8, 9, 0, 6};
  quick_sort(a, 0, 9);
  for (int i=0; i<10; i++) {
    std::cout << a[i] << " ";
    std::cout << std::endl;
    return 0;
  }
}
