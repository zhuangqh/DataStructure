#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename Comparable>
int partition(vector<int>& a, int low, int high) {
  int pivot = a[low];
  int i = low, j = low - 1;
  for (; i < high; ++i) {
    if (a[i] <= pivot) {
      ++j;
      if (i != j) swap(a[i], a[j]);
    }
  }

  swap(a[j+1], a[low]);

  return j + 1;
}

template <typename Comparable>
void quickSort(vector<Comparable>& a, int low, int high) {
  if (low < high) {
    int index = partition(a, low, high);
    quickSort(a, low, index - 1);
    quickSort(a, index + 1, high);
  }
}
