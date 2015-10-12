#include <iostream>
#include <stack>
#include <queue>

// simulate queue using two stack

using namespace std;

class Queue {
public:
  bool IsEmpty() const;
  int& front();
  void push(int a);
  void pop();
private:
  stack<int> s1;
  stack<int> s2;
};

bool Queue::IsEmpty() const {
  return s1.empty();
}

int& Queue::front() {
  while (!s1.empty()) {
    s2.push(s1.top());
    s1.pop();
  }

  int ans = s2.top();

  while (!s2.empty()) {
    s1.push(s2.top());
    s2.pop();
  }

  return ans;
}

void Queue::push(int a) {
  s1.push(a);
}

void Queue::pop() {
  while (!s1.empty()) {
    s2.push(s1.top());
    s1.pop();
  }

  s2.pop();

  while (!s2.empty()) {
    s1.push(s2.top());
    s2.pop();
  }
}
