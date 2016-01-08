/**
 * @Author: zhuangqh
 * @Email: zhuangqhc@gmail.com
 * @Create on: 2016-01-08 19:05
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 100000;

// prim algorithm
int getLongestRoad(int n, vector<vector<int> >& road) {
  vector<bool> visit(n+1, false);
  vector<int> dist(n+1, INF);
  int longest = -1;

  visit[1] = true;
  for (int i = 1; i <= n; ++i) {
    dist[i] = road[1][i];
  }

  for (int i = 1; i < n; ++i) {
    int min = INF, next;
    // find the minimum unknown distance
    for (int j = 2; j <= n; ++j) {
      if (!visit[j] && dist[j] < min) {
        next = j;
        min = dist[j];
      }
    }

    longest = max(longest, min);
    visit[next] = true;

    // update distance
    for (int k = 2; k <= n; ++k) {
      if (!visit[k] && road[next][k] < dist[k])
        dist[k] = road[next][k];
    }
  }

  return longest;
}

int main() {
  int kase;
  cin >> kase;
  while (kase--) {
    int n;
    cin >> n;
    vector<vector<int> > road(n+1, vector<int>(n+1));

    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        cin >> road[i][j];
      }
    }

    cout << getLongestRoad(n, road) << endl;

    if (kase > 0)
      cout << endl;
  }
  return 0;
}
