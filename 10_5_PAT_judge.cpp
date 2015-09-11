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
  string id;
  vector<int> question;
  int cpass;
  int total_score;
  int killed;
  personInfo(int n) {
    cpass = 0;
    total_score = 0;
    killed = 0;
    question.assign(n, -1);
  }
  void print(int rank);
};

void personInfo::print(int rank) {
  cout << rank << " " << id << " "
       << total_score;
  for (vector<int>::iterator it = ++question.begin();
       it != question.end(); ++it) {
    if (*it > -1) {
      cout << " " << *it;
    } else {
      cout << " -";
    }
  }

  cout << endl;
}

bool comp(const personInfo& a, const personInfo& b) {
  if (a.total_score == b.total_score) {
    if (a.killed == b.killed) {
      return a.id < b.id;
    } else {
      return a.killed > b.killed;
    }
  } else {
    return a.total_score > b.total_score;
  }
}

int str2num(const string &str) {
  int sum = 0;
  for (int i = 0; i < str.length(); ++i) {
    sum = sum*10 + str[i] - '0';
  }

  return sum;
}

int main() {
  cin >> n >> k >> m;
  vector<personInfo> table(n+1, personInfo(k+1));
  vector<int> board(k+1);

  for (int i = 1; i <= k; ++i) {
    cin >> board[i];
  }

  for (int i = 0; i < m; ++i) {
    string sid;
    int num, score;
    cin >> sid >> num >> score;
    //cout << "fuck\n";
    int id = str2num(sid);
    table[id].id = sid;

    // pass the compiler
    if (score > -1)
      ++table[id].cpass;

    // full mark
    if (score == board[num])
      ++table[id].killed;

    // update the score
    if (table[id].question[num] == -1) {
      if (score == -1) score = 0;
      table[id].total_score += score;
      table[id].question[num] = score;
    } else if (score > table[id].question[num]) {
      table[id].total_score += score - table[id].question[num];
      table[id].question[num] = score;
    }

  }

  sort(++table.begin(), table.end(), comp);

  int rank = 1;

  for (int i = 1; i <= n; ++i) {
    if (table[i].cpass == 0) continue;

    if (i == 1) {
      table[i].print(rank);
    } else if (table[i].total_score < table[i-1].total_score) {
      rank = i;
      table[i].print(rank);
    } else {
      table[i].print(rank);
    }
  }
  return 0;
}
