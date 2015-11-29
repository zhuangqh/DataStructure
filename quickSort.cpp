#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename Comparable>
int partition(vector<int>& a, int low, int high) {
  int pivot = a[low];
  int i = low + 1,    // used to scan through the list
    last_small = low;  // last one which smaller than pivot
  for (; i <= high; ++i) {
    if (a[i] < pivot) {
      ++last_small;
      swap(a[i], a[last_small]);
    }
  }

  swap(a[last_small], a[low]);

  return last_small;
}

template <typename Comparable>
void quickSort(vector<Comparable>& a, int low, int high) {
  if (low < high) {
    int index = partition<Comparable>(a, low, high);
    quickSort(a, low, index - 1);
    quickSort(a, index + 1, high);
  }
}
