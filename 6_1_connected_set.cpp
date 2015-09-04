#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, e;
vector<vector<bool> > graph;
vector<bool> visit;
vector<int> printQueue;

void dfs(int sta) {
  visit[sta] = true;
  printQueue.push_back(sta);
  for (int i = 0; i < n; ++i) {
    if (!visit[i] && graph[sta][i])
      dfs(i);
  }
}

void bfs(int sta) {
  queue<int> buf;
  buf.push(sta);
  printQueue.push_back(sta);
  visit[sta] = true;

  while (!buf.empty()) {
    int now = buf.front();
    buf.pop();

    for (int i = 0; i < n; ++i) {
      if (!visit[i] && graph[now][i]) {
        buf.push(i);
        printQueue.push_back(i);
        visit[i] = true;
      }
    }
  }

}

void printComponent() {
  cout << "{";
  for (vector<int>::iterator it = printQueue.begin();
       it != printQueue.end(); ++it) {
    cout << " " << *it;
  }
  cout << " }\n";
  printQueue.resize(0);
}

int main() {
  cin >> n >> e;
  // initialize
  for (int i = 0; i < n; ++i) {
    vector<bool> temp(n, false);
    graph.push_back(temp);
  }
  // read in graph
  for (int i = 0; i < e; ++i) {
    int x, y;
    cin >> x >> y;
    graph[x][y] = true;
    graph[y][x] = true;
  }

  // dfs
  visit.assign(n, false);
  for (int i = 0; i < n; ++i) {
    if (!visit[i]) {
      dfs(i);
      printComponent();
    }
  }

  // bfs
  visit.assign(n, false);
  for (int i = 0; i < n; ++i) {
    if (!visit[i]) {
      bfs(i);
      printComponent();
    }
  }
  return 0;
}
