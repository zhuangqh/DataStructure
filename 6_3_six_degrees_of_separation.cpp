#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>

using namespace std;
// @n: numbers of nodes @m numbers of eages
int n, m;
vector<vector<bool> > graph;
vector<int> visit;

struct node {
  int val;
  int step;
  node(int v, int s) : val(v), step(s) {}
};

int bfs(int sta) {
  queue<node> buf;
  int meet = 1;

  visit[sta] = true;
  buf.push(node(sta, 0));

  while (!buf.empty()) {
    node tmp = buf.front();
    buf.pop();

    if (tmp.step >= 6) continue;

    for (int i = 1; i <= n; ++i) {
      if (!visit[i] && graph[tmp.val][i]) {
        ++meet;
        visit[i] = true;
        buf.push(node(i, tmp.step + 1));
      }
    }
  }

  return meet;
}

int main() {
  cin >> n >> m;
  graph.assign(n+1, vector<bool>(n+1, false));

  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    graph[x][y] = true;
    graph[y][x] = true;
  }

  for (int i = 1; i <= n; ++i) {
    visit.assign(n+1, false);
    int meet = bfs(i);
    cout << i << ": " << setiosflags(ios::fixed) << setprecision(2)
         << (meet*1.0 / n)*100 << "%\n";
  }

  return 0;
}
