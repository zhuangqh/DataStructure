#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// according to the question length < 100
const int INF = 1000;

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int> > graph;

  for (int i = 0; i <= n; ++i) {
    vector<int> temp(n+1, INF);
    graph.push_back(temp);
  }

  // read in data
  for (int i = 0; i < m; ++i) {
    int x, y, len;
    cin >> x >> y >> len;

    graph[x][y] = graph[y][x] = len;
  }

  // Floyd-Warshall algorithm
  for (int k = 1; k <= n; ++k) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (graph[i][j] > graph[i][k] + graph[k][j])
          graph[i][j] = graph[i][k] + graph[k][j];
      }
    }
  }

  // find ans
  int minim = INF, ans, possi = false;
  for (int i = 1; i <= n; ++i) {
    bool all = true;
    int tmpMax = -1;
    for (int j = 1; j <= n; ++j) {
      if (i == j) continue;
      if (graph[i][j] == INF) all = false;

      if (graph[i][j] > tmpMax)
        tmpMax = graph[i][j];
    }

    if (all) possi = true;

    if (all && tmpMax < minim) {
      minim = tmpMax;
      ans = i;
    }
  }

  if (!possi) {
    cout << 0 << endl;
  } else {
    cout << ans << " " << minim << endl;
  }

  return 0;
}
