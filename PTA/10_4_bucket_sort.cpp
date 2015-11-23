#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> key(51, 0);

  for (int i = 0; i < n; ++i) {
    int temp;
    cin >> temp;
    ++key[temp];
  }

  for (int i = 0; i <= 50; ++i) {
    if (key[i] != 0) {
      cout << i << ":" << key[i] << endl;
    }
  }
  return 0;
}
