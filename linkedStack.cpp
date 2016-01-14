// create on 2016-01-14

#include <iostream>

enum ErrorCode {
  success,
  underflow,
  overflow
};

template <typename StackEntry>
struct Node {
  StackEntry data;
  Node *next;
  Node(StackEntry val, Node *ptr = NULL): data(val), next(ptr) {}
};

template <typename StackEntry>
class MyStack {
public:
  MyStack();
  bool empty() const;
  int size() const;
  ErrorCode pop();
  ErrorCode top(StackEntry& item) const;
  ErrorCode push(const StackEntry& item);
  void clear();
private:
  Node<StackEntry>* pTop;
};

template <typename StackEntry>
MyStack<StackEntry>::MyStack() {
  pTop = NULL;
}

template <typename StackEntry>
bool MyStack<StackEntry>::empty() const {
  return pTop == NULL;
}

template <typename StackEntry>
int MyStack<StackEntry>::size() const {
  Node<StackEntry> *ptr = pTop;
  int count = 0;
  while (ptr) {
    ++count;
    ptr = ptr->next;
  }
  return count;
}

template<typename StackEntry>
ErrorCode MyStack<StackEntry>::pop() {
  ErrorCode ans = success;
  if (empty()) {
    ans = underflow;
  } else {
    Node<StackEntry>* toDelete = pTop;
    pTop = pTop->next;
    delete toDelete;
  }
  return ans;
}

template<typename StackEntry>
ErrorCode MyStack<StackEntry>::top(StackEntry& item) const {
  if (empty()) {
    return underflow;
  } else {
    item = pTop->data;
    return success;
  }
}

template <typename StackEntry>
ErrorCode MyStack<StackEntry>::push(const StackEntry& item) {
  Node<StackEntry> *newNode = new Node<StackEntry>(item);
  newNode->next = pTop;
  pTop = newNode;
  return success;
}

template <typename StackEntry>
void MyStack<StackEntry>::clear() {
  Node<StackEntry> *toDelete = NULL;
  while (pTop) {
    toDelete = pTop;
    pTop = pTop->next;
    delete toDelete;
  }
}
