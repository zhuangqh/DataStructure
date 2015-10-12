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
    a[0] = 1;

    for (int i = 1; i <= n; ++i) {
      int sum = 0;
      for (int j = 0; j <= i -1; ++j) {
        sum += a[j]*a[i-1-j];
      }

      a[i] = sum;
    }
    cout << a[n] << endl;
  }

  return 0;
}
