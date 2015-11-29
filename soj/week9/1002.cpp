#include <iostream>
#include <vector>

using namespace std;

void heapAdjust(vector<int>& v, int i, int size) {
  int left = 2*i;
  int right = 2*i+1;
  int max = i;

  if (i <= size/2) {
    if (left <= size && v[left] > v[max]) max = left;
    if (right <= size && v[right] > v[max]) max = right;

    if (max != i) {
      swap(v[i], v[max]);
      heapAdjust(v, max, size);
    }
  }
}

void buildHeap(vector<int>& v, int size) {
  for (int i = size/2 - 1; i >= 0; --i)
    heapAdjust(v, i, size);
}

void output(vector<int>& v) {
  bool isfirst = true;
  for (int i = 1; i < v.size(); ++i) {
    if (isfirst) isfirst = false;
    else cout << " ";
    cout << v[i];
  }

  cout << endl;
}

void heapSort(vector<int>& v, int size) {
  for (int i = size - 1; i >= 1; i--) {
    output(v);
    swap(v[0], v[i]);
    heapAdjust(v, 0, i);
  }
}

int main() {
  int n;
  while (cin >> n) {
    vector<int> v(n);
    for (int i = 0; i <= n; ++i)
      cin >> v[i];

    buildHeap(v, n);
    heapSort(v, n);
  }

  return 0;
}
