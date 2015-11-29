#include <iostream>
#include <vector>
#include <cstdio>

// definition of a record
template <typename Record>
struct Node {
  Record entry;
  Node<Record> *next;
  Node<Record>(): entry(0), next(NULL) {}
  Node<Record>(Record v): entry(v), next(NULL) {}
};

template <typename Record>
void mergeSort(Node<Record>* &sublist) {
  if (sublist != NULL && sublist->next != NULL) {
    Node<Record>* secondlist = divide_from(sublist);
    mergeSort(sublist);
    mergeSort(secondlist);
    sublist = merge(sublist, secondlist);
  }
}

template <typename Record>
Node<Record>* divide_from(Node<Record>* &sublist) {
  Node<Record> *pos, *mid, *secondlist;

  if ((mid = sublist) == NULL) return NULL;
  pos = mid->next;
  while (pos != NULL) {
    pos = pos->next;
    if (pos != NULL) {
      mid = mid->next;
      pos = pos->next;
    }
  }

  secondlist = mid->next;
  mid->next = NULL;
  return secondlist;
}

template <typename Record>
Node<Record>* merge(Node<Record>* &first, Node<Record>* &second) {
  Node<Record>* last;
  Node<Record> combined; // zombie node
  last = &combined;
  while (first != NULL && second != NULL) {
    if (first->entry <= second->entry) {
      last->next = first;
      last = first;
      first = first->next;
    } else {
      last->next = second;
      last = second;
      second = second->next;
    }
  }

  if (first == NULL)
    last->next = second;
  else
    last->next = first;
  return combined.next;
}
