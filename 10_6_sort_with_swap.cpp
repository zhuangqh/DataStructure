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

  int count, ptr, sum = 0, flag;
  for (int i = 0; i < n; ++i) {
    flag = true;
    count = 1;

    if (table[i] != i) {
      if (i == 0) flag = false;
      ptr = table[i];
      table[i] = i;

      while (ptr != i) {
        if (ptr == 0) flag = false;
        ++count;
        int temp = ptr;
        ptr = table[ptr];
        table[temp] = temp;
      }

      if (flag)
        sum += count + 1;
      else
        sum += count - 1;
    }
  }

  cout << sum << endl;
  return 0;
}
