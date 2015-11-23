#include <iostream>
#include <vector>

using namespace std;

const int INF = 10000;

vector<vector<int> > road;
vector<vector<int> > cost;

void dijkstra(int n, int sta, vector<int> &dist, vector<int> &price) {
  vector<bool> visit(n, false);

  for (int i = 0; i < n; ++i) {
    if (road[sta][i] < INF) {
      dist[i] = road[sta][i];
      price[i] = cost[sta][i];
    }
  }

  visit[sta] = true;

  int min, pos;
  for (int i = 0; i < n; ++i) {
    min = INF;
    pos = sta;

    for (int j = i; j < n; ++j) {
      if (!visit[j] && dist[j] < min) {
        min = dist[j];
        pos = j;
      }
    }

    visit[pos] = true;

    for (int j = 0; j < n; ++j) {
      if (!visit[j] && dist[pos] + road[pos][j] < dist[j]) {

        dist[j] = dist[pos] + road[pos][j];
        price[j] = price[pos] + cost[pos][j];
      } else if (dist[pos] + road[pos][j] == dist[j]
                 && price[j] > price[pos] + cost[pos][j]) {

        price[j] = price[pos] + cost[pos][j];
      }
    }
  }
}

int main() {
  int n, m, sta, end;
  cin >> n >> m >> sta >> end;

  road.assign(n, vector<int>(n, INF));
  cost.assign(n, vector<int>(n, INF));

  for (int i = 0; i < m; ++i) {
    int x, y, length, price;
    cin >> x >> y >> length >> price;
    road[x][y] = road[y][x] = length;
    cost[x][y] = cost[y][x] = price;
  }

  vector<int> dist(n, INF);
  vector<int> price(n, INF);

  dijkstra(n, sta, dist, price);

  cout << dist[end] << " " << price[end] << endl;
  return 0;
}
