#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, k;
  while (cin >> n) {
    cin >> k;
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
      cin >> v[i];

    sort(v.begin(), v.end());
    bool isfirst = true;

    for (int i = n - 1; i > n - 1 - k; --i) {
      if (isfirst) isfirst = false;
      else cout << " ";
      cout << v[i];
    }

    cout << endl;
  }
}
