#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// n : total number of users
// k : total number of problems
// m : total number of submittions
int n, k, m;

struct personInfo {
  vector<int> question;
  int ok;
  int killed;
  personInfo(int n) {
    ok = 0;
    killed = 0;
    question.assign(n, -1);
  }
};

int str2num(const string &str);
int main() {
  cin >> n >> k >> m;
  vector<personInfo> table(n);
  vector<int> board(k);

  for (int i = 0; i < k; ++i) {
    cin >> board[i];
  }

  for (int i = 0; i < m; ++i) {
    string sid;
    int num, score;
    cin >> sid >> num >> score;


  }
  return 0;
}
