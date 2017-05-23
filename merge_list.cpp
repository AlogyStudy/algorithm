
#include <iostream>

struct node{
  int payload;
  node* next;
  node(int payload) {this->payload = payload; next = nullptr;};
};

class linkedlist{
  node *head, *tail;
public:
  //constructor, initialize head and tail to nullptr
  linkedlist() : head(nullptr),tail(nullptr){};
  //push a new node at the end of the list
  void push_back(int value){
    if(empty()){ 
      head = tail = new node(value);
    }else{      
      tail->next = new node(value);
      tail = tail->next;
    }
  }
  //return the value stored in the first node
  int front(){
    if(empty()){
      throw "The list is empty.";
    }
    return head->payload;
  }
  //remove the first node
  void pop_front(){
    if(empty()){
      throw "The list is empty.";
    }
    node* first_node = head;
    head = head->next;
    delete first_node; 
  }
  bool empty(){
    return head == nullptr;
  }
  void output(){
    node* iterator = head;
    while(iterator){
      std::cout << iterator->payload << " ";
      iterator = iterator->next;
    }
    std::cout << std::endl;
  }
  
};

//merge two sorted linked list, return a new list
linkedlist merge(linkedlist a, linkedlist b){
  linkedlist result;
  while(!a.empty() || !b.empty()){ // 考虑极端情况， a 链表为空，把b链表中的一个个添加 结果链表中； b 链表为空，把a链表中的一个个添加 结果链表中
    if(a.empty()){
      result.push_back(b.front());
      b.pop_front();
    }else if(b.empty()){
      result.push_back(a.front());
      a.pop_front();
    }else if(a.front() > b.front()){ // a，b 链表都不为空， 看a和b 的head 谁大 (比较值的大小)。 a > b , b添加到结果链表中
      result.push_back(b.front());
      b.pop_front();
    }else{
      result.push_back(a.front()); // a < b ， a添加到结果链表中
      a.pop_front();
    }
  }
  return result;
}

/**
逻辑上的循环，并不知道具体会循环多少次，**去看关键逻辑**。

a的长度是m，b的长度是n。
总共循环了`m+n`次。
```
(m+n) * O(1)

时间复杂度为：
O(m+n)
```
*/
int main(){

  linkedlist a,b;
  
  linkedlist result = merge(a, b);
  result.output();
  return 0;
}