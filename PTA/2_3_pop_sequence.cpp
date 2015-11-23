#include <iostream>
#include <stack>
#include <vector>

int main() {
  int s_size, n, kase;
  std::cin >> s_size >> n >> kase;

  while (kase--) {
    std::vector<int> vec;
    // read in data
    for (int i = 0; i < n; ++i) {
      int temp;
      std::cin >> temp;
      vec.push_back(temp);
    }

    std::stack<int> s;
    int num = 0, count = 0;

    for (int i = 0; i < n; ++i) {
      if (s.empty()) s.push(++num);

      while (s.top() != vec[i] && num <= n && s.size() < s_size) {
        s.push(++num);
      }

      if (s.top() == vec[i]) {
        ++count;
        s.pop();
      }

    }

    std::cout << (count == n ? "YES\n" : "NO\n");
  }

  return 0;
}
