/**
 * @Author: zhuangqh
 * @Email: zhuangqhc@gmail.com
 * @Create on: 2016-01-07 14:09:47
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct node {
  int salary;
  int indegree;
  int index;
  vector<int> next;
  node(): salary(100), indegree(0), index(0), next() {}
};

void topoSort(vector<node>& worker, int& n) {
  int count = 0, sum = 0;
  queue<node> buf;
  for (int i = 1; i <= n; ++i) {
    if (worker[i].indegree == 0) {
      buf.push(worker[i]);
      count++;
    }
  }

  while (!buf.empty()) {
    node tmp = buf.front();
    sum += tmp.salary;
    buf.pop();
    for (int i = 0; i < tmp.next.size(); ++i) {
      node& now = worker[tmp.next[i]];
      if (--now.indegree == 0) {
        now.salary = tmp.salary + 1;
        buf.push(now);
        count++;
      }
    }
  }

  if (count != n) {
    cout << "Poor Xed\n";
  } else {
    cout << sum << endl;
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<node> worker(n + 1);

  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> b >> a;
    worker[a].next.push_back(b);
    worker[b].indegree++;
  }

  topoSort(worker, n);

  return 0;
}
