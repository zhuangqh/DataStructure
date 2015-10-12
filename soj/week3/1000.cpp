#include <iostream>
#include <vector>

// jump ladder problem
// jump 1 or 2 footstep one time
using namespace std;

int main() {

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n+1, 0);

    a[1] = 1;
    a[2] = 2;

    for (int i = 3; i <= n; ++i) {
      a[i] = a[i-1] + a[i-2];
    }

    cout << a[n] << endl;
  }

  return 0;
}
