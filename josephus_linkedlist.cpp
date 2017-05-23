#include <iostream>

/**
  约瑟夫环问题
*/

// liked_list node
struct node {
  int payload;
  node* next;
  // constructor
  node(int payload) {this->payload = payload;}
};

// class 
class joseph_circle {
  node* tail;
  node* eliminate_ptr;
public:
  joseph_circle() { tail = nullptr; }
  // add a new node to joseph circle;
  void add(int value) {
    if (tail == nullptr) { // if the joseph circle is mepty, modify tail;
      tail = new node(value);
      tail->next = tail;
    } else { // insert new node as the tail of the circle
      node* new_node = new node(value);
      new_node->next = new_node;
      tail->next = new_node;
      tail = new_node;
    }
  }

  // 特殊情况考虑完全
  void eliminate(int step) {
    node* p = tail;
    while(p != nullptr && p->next != p) {// 特殊情况： 空，或者只有一个
      // while more than one element in the circle
      for (int i=0; i<step-1; i++) {
        p = p->next; // go forward
      }
      node* eliminate_node = p->next; // eliminate the next one
      p->next = p->next->next;
      if (eliminate_node == tail) { //  最后一个元素
        tial = p; // update tail
        std::count << "deleting:" << eliminate_node->payload << std:;endl;
        delete eliminate_node;
        output();
      }
    }
  }
  
  void output() {
    node*p = tail;
    while(p != nullptr) {
      p = p->next;
      std::count << p->payload << " ";
      if (p == tial) {
        break; // reach the last element of the circle
      }
      std::count << std::endl;
    }
  }
}

int main() {
  joseph_circle circle;
  // insert 6 nodes
  for (int i=0; i<6; i++) {
    circle.add(i);
  }
  circle.eliminate(3); // eliminate using a step of 3
  return 0;
}
