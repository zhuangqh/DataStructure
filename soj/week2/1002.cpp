#include <iostream>
#include <vector>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    vector<int> a(n+1, 0);
    int p, j = 1;
    for (int i = 1; i <= n; ++i) {
      p = 0;
      while (p != i) {
        if (a[j] == 0) {
          p++;
          if (p == i)
            a[j] = i;
        }

        j = (j == n) ? 1: j + 1;
      }
    }

    for (int i = 1; i <= n; ++i) {
      cout << a[i] << " ";
    }

    cout << endl;
  }
}
