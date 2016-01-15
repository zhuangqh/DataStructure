// create on 2016-01-15
#include <iostream>

enum ErrorCode {
	success,
	underflow,
	overflow
};

template <class QueueEntry>
struct Node {
	QueueEntry data;
    Node<QueueEntry> *next;
    Node(QueueEntry val): data(val), next(NULL) {}
};

template <typename QueueEntry>
class MyQueue {
	public:
		MyQueue();
		bool empty() const;
		ErrorCode append(const QueueEntry& item);
		ErrorCode serve();
		ErrorCode retrieve(QueueEntry& item) const;
		int size() const;
		void clear();
		ErrorCode retrieve_and_serve(QueueEntry& item);
	private:
		Node<QueueEntry>* front;
		Node<QueueEntry>* rear; 
}; 

template <typename T>
MyQueue<T>::MyQueue() {
	front = rear = NULL;
} 

template <typename T>
bool MyQueue<T>::empty() const {
	return front == NULL;
}

template <typename T>
ErrorCode MyQueue<T>::append(const T& item) {
	Node<T> *newNode = new Node<T>(item);
	if (empty()) {
		front = rear = newNode;
	} else {
		rear->next = newNode;
		rear = newNode;
	}
	return success;
}

template <typename T>
ErrorCode MyQueue<T>::serve() {
	Node<T>* toDelete = NULL;
	ErrorCode ans = success;
	if (empty()) {
		ans = underflow;
	} else if (size() == 1) {
		toDelete = front;
		front = rear = NULL;
		delete toDelete;
	} else {
		toDelete = front;
		front = front->next;
		delete toDelete;
	}
	return ans;
}

template <typename T>
ErrorCode MyQueue<T>::retrieve(T& item) const {
	ErrorCode ans = success;
	if (empty()) {
		ans = underflow;	
	} else {
		item = front->data;
	}
	return ans;
}

template <typename T>
int MyQueue<T>::size() const {
	Node<T>* ptr = front;
	int count = 0;
	while (ptr) {
		ptr = ptr->next;
		++count;
	}
	return count;
}

template <typename T>
void MyQueue<T>::clear() {
	Node<T>* toDelete = NULL;
	while (front) {
		toDelete = front;
		front = front->next;
		delete toDelete;
	}
	front = rear = NULL;
}

template <typename T>
ErrorCode MyQueue<T>::retrieve_and_serve(T& item) {
	ErrorCode ans = success;
	ans = retrieve(item);
	serve();
	return ans;
}

