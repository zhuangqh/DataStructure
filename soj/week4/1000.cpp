#include <iostream>
#include <vector>
enum ErrorCode {
  success,
  underflow,
  overflow
};

template <class StackEntry>
struct Node {
  StackEntry data;
  Node *next;
  Node(StackEntry d) : data(d), next(NULL) {}
};

template<class StackEntry>
class MyStack {
public:
  MyStack();
  bool empty() const;
  int size() const;
  ErrorCode pop();
  ErrorCode top(StackEntry &item) const;
  ErrorCode push(const StackEntry &item);
  void clear();
private:
  Node<StackEntry> *ptop;
};

template<typename T>
MyStack<T>::MyStack() {
  ptop = NULL;
}

template<typename T>
bool MyStack<T>::empty() const {
  return (ptop == NULL);
}

template<typename T>
int MyStack<T>::size() const {
  Node<T> *p = ptop;
  int size = 0;
  while (p) {
    ++size;
    p = p->next;
  }

  return size;
}

template<typename T>
ErrorCode MyStack<T>::pop() {
  if (empty()) {
    return underflow;
  } else {
    Node<T> *tmp = ptop;
    ptop = ptop->next;
    delete tmp;
    return success;
  }
}

template<typename T>
ErrorCode MyStack<T>::top(T &item) const {
  if (empty()) {
    return underflow;
  } else {
    item = ptop->data;
    return success;
  }
}

template<typename T>
ErrorCode MyStack<T>::push(const T&item) {
  Node<T> *nn = new Node<T>(item);
  if (empty()) {
    ptop = nn;
  } else {
    nn->next = ptop;
    ptop = nn;
  }
  return success;
}

template<typename T>
void MyStack<T>::clear() {
  ptop = NULL;
}
