#include <iostream>

int main()
{
  int array[] = {5, 4, 10, 1, 7, 9, 2};

  std::cout << array[4] << std::endl;
  std::cout << *(array + 4) << std::endl;
  return 0;
}

// 移动和插入，删除，需要耗费性能和时间，就是链表产生的原因
