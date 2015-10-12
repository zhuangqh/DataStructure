#include <iostream>
#include <vector>

using namespace std;

enum ErrorCode{
         success,
         underflow,
         overflow
};

const int maxStack = 100;

template<typename T>
class MyStack {
public:
  MyStack() {size = 0;}
  bool empty() const {return size == 0;}
  ErrorCode pop() {
    if (size >= 1) {
      --size;
      return success;
    } else {
      return underflow;
    }
  }
  ErrorCode top(T& item) const {
    if (size == 0) {
      return underflow;
    } else {
      item = s[0];
      return success;
    }
  }
  ErrorCode push(const T  &item) {
    if (size == maxStack) {
      return overflow;
    } else {
      s[size++] = item;
    }
  }
private:
  int size;
  T s[maxStack];
};
