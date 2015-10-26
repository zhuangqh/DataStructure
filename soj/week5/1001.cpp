#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    vector<int> m(n);
    for (int i = 0; i < n; ++i) {
      m[i] = i+1;
    }

    do {
      for (int i = 0; i < n; ++i) {
        cout << m[i];
      }
      cout << endl;
    } while (next_permutation(m.begin(), m.end()));
  }

  return 0;
}
