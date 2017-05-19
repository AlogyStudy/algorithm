#include <iostream>

struct node {
  int payload;
  node* next; // 指针指向下一个元素
};


// 递归实现链表反序
node* reverse_recursive(node* head) {
  if (head == nullptr || head->next == nullptr) 
    return head;
  node* second = head->next;   
  node* new_head = reverse_recursive(second);  // 从第二个单元开始循环判断
  second->next = head; // 重新构建 第二个单元
  head->next = nullptr;
  return new_head;
}

// 普通方法实现链表反转 
node* reverse(node* head) { // O(n)
  if (head == nullptr || head->next == nullptr) 
    return head;
  node* p = head->next;
  node* p_previous = head;
  head->next = nullptr;
  while(p != nullptr) { 
    node* p_next = p->next;
    p->next = p_previous;
    p_pervious = p;
    p = p_next;
  }
}


int main() {
  node* head = nullptr;
  // insert 10 nodes
  for (int i=0; i<10; i++) {  // 可以在内存中任意一个位置，通过next，找到后边的元素. (解决插入，删除的性能问题)
    node* new_node = new node;
    new_node->payload = i * 10;
    new_node->next = head;
    head = new_node;
  }
  head = reverse_recursive(head);
  // output each node in the linked-list
  node* iterator = head; // 循环输出
  while(iterator) {
    std::cout << interator->payload << std::endl;
    iterator = interator->next;
  }
  return 0;
}