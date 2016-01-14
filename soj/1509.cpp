// create on 2016-01-14

#include <iostream>
#include <vector>
#include <stack>


using namespace std;

void solve(vector<int>& coaches) {
  int n = coaches.size() - 1;
  int ptr = 1;
  stack<int> s;

  for (int i = 1; i <= n; ++i) {

    while (ptr <= n && ptr <= coaches[i]) {
      s.push(ptr++);

    }

    if (!s.empty() && s.top() == coaches[i])
      s.pop();

  }
  s.empty()
    ? cout << "Yes\n"
    : cout << "No\n";
}

int main() {
  int n;
  while (cin >> n && n) {
    vector<int> coaches(n+1);
    while (cin >> coaches[1] && coaches[1]) {
      for (int i = 2; i <= n; ++i)
        cin >> coaches[i];
      solve(coaches);
    }

    cout << endl;
  }

  return 0;
}
