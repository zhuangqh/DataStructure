#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct tt {
  int pre, rear;
};

bool cmp(const tt& a, const tt& b) {
  return (a.rear < b.rear);
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int kase;
    cin >> kase;

    tt t[200];

    for (int i = 0; i < kase; ++i) {
      cin >> t[i].pre >> t[i].rear;
    }

    sort(t, t + kase, cmp);

    int ans = 0;
    tt tmp;
    for (int i = 0; i < kase; ++i) {
      if (i == 0) {
        ++ans;
        tmp = t[0];
        continue;
      }

      if (t[i].pre > tmp.rear) {
        tmp = t[i];
        ++ans;
      }
    }

    cout << ans << endl;
  }
  return 0;
}
