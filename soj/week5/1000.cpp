#include <iostream>
#include <string>
#include <sstream>

using namespace std;
bool isfirst = true;

string int2str(int x) {
  stringstream ss;
  ss << x;
  string ans;
  ss >> ans;
  return ans;
}

void split(string combstr, int n, int curtotal, int total) {
  if (curtotal == total)
    cout << combstr << endl;

  for (int i = n; i > 0; --i) {
    if (curtotal + i == total) {
      cout << combstr << "+" << int2str(i) << endl;
    } else if (curtotal + i < total) {
      split(combstr + "+" + int2str(i), i, curtotal + i, total);
    }
  }
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = n; i >= 1; --i) {
      split(int2str(i), i, i,  n);
    }
  }
 return 0;
}
