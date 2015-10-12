#include <vector>
enum ErrorCode {
  success,
  underflow,
  overflow
};

const int maxQueue = 100;

template<typename T>
class MyQueue {
public:
  MyQueue() {
    front = rear = 0;
  }
  bool empty() const {
    return rear == front;
  }
  ErrorCode append(const T& item) {
    if (full()) {
      return overflow;
    } else {
      s[rear] = item;
      rear = (rear + 1) % maxQueue;
      return success;
    }
  }
  ErrorCode serve() {
    if (empty()) {
      return underflow;
    } else {
      front = (front+1) % maxQueue;
      return success;
    }
  }
  ErrorCode retrieve(T &item) const {
    if (empty()) {
      return underflow;
    } else {
      item = s[front];
      return success;
    }
  }
  bool full() const {
    return ((rear+1) % maxQueue == front);
  }
  int size() const {
    return (rear - front + maxQueue) % maxQueue;
  }
  void clear() {
    front = rear = 0;
  }
  ErrorCode retrieve_and_serve(T &item) {
    if (empty()) {
      return underflow;
    } else {
      item = s[front];
      front = (front + 1) % maxQueue;
      return success;
    }
  }
private:
  int front;
  int rear;
  T s[100];
};
