#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> vec(n);

  for (int i = 0; i < n; ++i) {
    int temp;
    cin >> temp;
    vec[i] = temp;
  }

  sort(vec.begin(), vec.end());

  bool isfirst = true;
  for (int i = 0; i < n; ++i) {
    if (isfirst) isfirst = false;
    else cout << " ";

    cout << vec[i];
  }

  cout << endl;
  return 0;
}
