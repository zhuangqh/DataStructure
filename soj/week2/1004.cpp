#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    queue<int> buf;

    for (int i = 1; i <= n; ++i) {
      buf.push(i);
    }

    while (buf.size() >= 2) {
      int out = buf.front();
      buf.pop();
      cout << out << " ";

      int f = buf.front();
      buf.pop();
      buf.push(f);
    }

    cout << buf.front() << " \n";
  }
  return 0;
}
