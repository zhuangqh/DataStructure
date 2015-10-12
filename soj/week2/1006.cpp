#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    vector<int> vec;
    for (int i = 1; i <= 10; ++i) {
      int temp;
      cin >> temp;
      vec.push_back(temp);
    }

    stack<int> s;
    int num = 0,  count = 0;

    for (int i = 0; i < 10; ++i) {
      if (s.empty()) s.push(++num);

      while (s.top() != vec[i] && num <= 10) {
        s.push(++num);
      }

      if (s.top() == vec[i]) {
        ++count;
        s.pop();
      }
    }

    cout << ((count == 10) ? "Yes\n" : "No\n");
  }

  return 0;
}
