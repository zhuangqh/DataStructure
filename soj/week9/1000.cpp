#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> v(n, 0);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }

  sort(v.begin(), v.end());
  bool isfirst = true;

  // output
  for (int i = 0; i < n; ++i) {
    if (isfirst) isfirst = false;
    else cout << " ";

    cout << v[i];
  }

  cout << endl;
  if (n % 2 == 0) {
    cout << (v[n/2] + v[n/2 - 1]) /  2;
  } else {
    cout << v[n/2];
  }
  return 0;
}
