#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<string> v;
  string dict;
  cin >> dict;

  for (int i = 0; i < dict.length(); ++i) {
    string tmp = "0";
    tmp[0] = dict[i];
    v.push_back(tmp);
  }

  string input;
  cin >> input;
  string output;

  bool isfirst = true;
  int index = 0;
  for (int i = 0; i < input.length(); i++) {
    if (input[i] == '0') {
      if (isfirst) isfirst = false;
      else cout << " ";
      cout << output;
      v.push_back(output);
      output = "";
    } else if (input[i] != '-'){
      index = 0;
      while (input[i] >= '0' && input[i] <= '9') {
        index = index * 10 + input[i] - '0';
        i++;
      }
      i--;
      output += v[index - 1];
    }
  }

  cout << endl;
  return 0;
}
