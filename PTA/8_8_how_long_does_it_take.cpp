#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 100000;

struct node {
  int timeUsed;
  int indegree;
  vector<int> next;
  node(int t, int i) : timeUsed(t), indegree(i) {}
};

void topoSort(vector<vector<int> > &eage, vector<node> &acti, int n) {
  queue<int> buf;
  int count = 0, result = 0;

  for (int i = 0; i < n; ++i) {
    if (acti[i].indegree == 0) {
      buf.push(i);
      ++count;
    }
  }

  while (!buf.empty()) {
    int cur = buf.front();
    buf.pop();

    for (vector<int>::iterator it = acti[cur].next.begin();
         it != acti[cur].next.end(); ++it) {
      if (acti[cur].timeUsed + eage[cur][*it]) {
        acti[*it].timeUsed = acti[cur].timeUsed + eage[cur][*it];
      }

      if (acti[*it].timeUsed > result) result = acti[*it].timeUsed;

      if (--acti[*it].indegree == 0) {
        buf.push(*it);
        ++count;
      }
    }
  }

  if (count != n) {
    cout << "Impossible\n";
  } else {
    cout << result << endl;
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int> > eage(n, vector<int>(n, INF));
  vector<node> activity(n, node(0, 0));

  for (int i = 0; i < m; ++i) {
    int x, y, t;
    cin >> x >> y >> t;
    eage[x][y] = t;
    activity[x].next.push_back(y);
    ++activity[y].indegree;
  }

  topoSort(eage, activity, n);
  return 0;
}
