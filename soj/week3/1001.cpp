#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <map>

// parenthesis match
using namespace std;

int main() {
  int t;
  cin >> t;

  map<char, char> mp;
  mp[')'] = '(';
  mp[']'] = '[';
  mp['}'] = '{';

  string ttmp;
  getline(cin, ttmp);

  while (t--) {
    string str;
    getline(cin, str);

    bool ans = true;
    stack<char> ss;
    for (int i = 0; i < str.length(); ++i) {
      // just care parenthesis
      if (str[i] == '(' || str[i] == ')' || str[i] == '{' || str[i] == '}'
          || str[i] == '[' || str[i] == ']') {

        if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
          ss.push(str[i]);
        } else {

          if (ss.empty()) {
            ans = false;
            break;
          } else {
            char tmp = ss.top();
            ss.pop();
            if (tmp != mp[str[i]]) {
              ans = false;
              break;
            }
          }
        }
      }
    }


    if (!ss.empty()) ans = false;

    cout << (ans ? "True\n" : "False\n");
  }

  return 0;
}
