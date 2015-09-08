#include <iostream>
#include <vector>

using namespace std;

void insertionSort(vector<int> &origin, vector<int> &table, int n) {
  table[0] = 0;
  for (int i = 1; i < n; ++i) {
    if (origin[i-1] > origin[i]) {
      int temp = origin[i];
      int j = i;
      while (j > 0 && origin[j-1] > temp) {
        origin[j] = origin[j-1];
        table[j] = table[j-1];
        --j;
      }

      origin[j] = temp;
      table[j] = i;
    } else {
      table[i] = i;
    }
  }
}

int main() {
  int n;
  cin >> n;
  vector<int> origin(n, 0);
  vector<int> table(n, 0);

  for (int i = 0; i < n; ++i) {
    int temp;
    cin >> temp;
    origin[i] = temp;
  }

  insertionSort(origin, table, n);

  // S : single circle
  // K : multiply circle
  int S = 0, K = 0, ptr;
  for (int i = 0; i < n; ++i) {
    if (table[i] == -1) continue;
    if (table[i] != i) {
      ptr = table[i];
      table[i] = -1;

      while (ptr != i) {
        int temp = ptr;
        ptr = table[ptr];
        table[temp] = -1;
      }
      ++K;
    } else {
      ++S;
    }
  }
  if (S && !K)
    cout << "0\n";
  else
    cout << (n-S+K-2) << endl;
  return 0;
}
