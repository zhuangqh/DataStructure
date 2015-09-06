#include <iostream>
#include <vector>

using namespace std;

const int INF = 10000;

void solution(int n, const vector<vector<int> > &road) {
  vector<bool> visit(n+1, false);
  vector<int> low(n+1, INF);

  int pos = 1, min, count = 0, len = 0;
  visit[1] = true;

  for (int i = 1; i <= n; ++i) {
    if (i != pos) low[i] = road[pos][i];
  }

  for (int i = 1; i < n; ++i) {
    min = INF;

    // find the least weight and set position
    for (int j = 1; j <= n; ++j) {
      if (!visit[j] && low[j] < min) {
        min = low[j];
        pos = j;
      }
    }

    len += min;
    ++count;

    visit[pos] = true;

    for (int j = 1; j <= n; ++j) {
      if (!visit[j] && road[pos][j] < low[j])
        low[j] = road[pos][j];
    }
  }

  if (count != n - 1)
    cout << "-1\n";
  else
    cout << len << endl;
}

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int> > road(n+1, vector<int>(n+1, INF));

  for (int i = 0; i < m; ++i) {
    int x, y, cost;
    cin >> x >> y >> cost;
    road[x][y] = road[y][x] = cost;
  }

  solution(n, road);
  return 0;
}
