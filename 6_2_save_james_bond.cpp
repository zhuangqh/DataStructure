#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
vector<vector<bool> > graph;
vector<vector<bool> > visit;
int n, d;
bool success = false;


bool escape(int x, int y) {
  return (x + d >= 100) || (x - d <= 0) ||
    (y + d >= 100) || (y - d <= 0);
}
bool isOK(int x1, int y1, int x2, int y2) {
  double distance = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
  return distance <= d;
}

void dfs(int x, int y) {
  visit[x][y] = true;
  if (escape(x, y))
    success = true;
  if (success) return;

  for (int i = x - d; i <= x + d; ++i) {
    for (int j = y - d; j <= y + d; ++j) {
      if (graph[i][j] && !visit[i][j] && isOK(i, j, x, y)) {
        dfs(i, j);
        visit[i][j] = false;
      }
    }
  }
}

int main() {
  cin >> n >> d;
  // initialize
  for (int i = 0; i <= 100; ++i) {
    vector<bool> temp(101, false);
    vector<bool> v(101, false);
    graph.push_back(temp);
    visit.push_back(v);
  }

  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    graph[x + 50][y + 50] = true;
  }

  for (int i = 50-15-d; i <= 50+15+d; ++i) {
    for (int j = 50-15-d; j <= 50+15+d; ++j) {
      dfs(i, j);
    }
  }

  cout << (success ? "Yes\n" : "No\n");
  return 0;
}
