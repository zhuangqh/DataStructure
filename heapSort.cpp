#include <iostream>
#include <vector>

using namespace std;

template <typename Comparable>
void percDown(vector<Comparable>& a, int i, int n) {
  int child;
  Comparable tmp;
  for (tmp = a[i]; 2 * i + 1 < n; i = child) {
    child = 2 * i + 1;
    if (child != n -1 && a[child] < a[child + 1])
      ++child;
    if (tmp < a[child])
      a[i] = a[child];
    else
      break;
  }
  a[i] = tmp;
}

// increasing sorted order
template <typename Comparable>
void heapSort(vector<Comparable>& a) {
  // build heap
  for (int i = a.size() / 2 - 1; i >= 0; --i)
    percDown(a, i, a.size());

  // delete max
  for (int j = a.size() - 1; j > 0; --j) {
    swap(a[0], a[j]);
    percDown(a, 0, j);
  }
}
