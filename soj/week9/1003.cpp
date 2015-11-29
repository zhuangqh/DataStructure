#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void output(vector<int>& a) {
  for (int i = 0; i < a.size(); ++i) {
    cout << a[i] << " ";
  }

  cout << endl;
}

int main() {

  int m, n;
  while (cin >> m) {
    cin >> n;
    vector<int> a(m), b(n);
    for (int i = 0; i < m; ++i)
      cin >> a[i];
    for (int i = 0; i < n; ++i)
      cin >> b[i];

    // jiao ji
    vector<int> jiao;
    for (int i = 0; i < m; ++i) {
      if (find(b.begin(), b.end(), a[i]) != b.end()) {
        jiao.push_back(a[i]);
      }
    }
    output(jiao);

    // bing ji
    vector<int> bing = a;
    for (int i = 0 ; i < n; ++i) {
      if (find(a.begin(), a.end(), b[i]) == a.end()) {
        bing.push_back(b[i]);
      }
    }

    output(bing);

    // cha
    vector<int> cha;
    for (int i = 0; i < m; ++i) {
      if (find(b.begin(),  b.end(), a[i]) == b.end()) {
        cha.push_back(a[i]);
      }
    }

    output(cha);
  }
}
