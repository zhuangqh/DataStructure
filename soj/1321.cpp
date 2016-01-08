/**
 * @Author: zhuangqh
 * @Email: zhuangqhc@gmail.com
 * @Create on: 2016-01-08 15:58
 */

#include <iostream>
#include <vector>

using namespace std;

const int INF = 100000; // the max height in this problem is 9999

struct vertex {
  bool known;
  int height;
  vertex(): known(false), height(INF) {}
};

const int dir[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

inline bool isValid(int row, int col, int x, int y) {
  return x >= 0 && x < row && y >= 0 && y < col;
}

void solve(int sta_x, int sta_y, int ed_x, int ed_y,
           int row, int col, vector<vector<vertex> >& graph);

int main() {
  int kase;
  cin >> kase;
  while (kase--) {
    int row, col;
    cin >> row >> col;
    vector<vector<vertex> > graph(row, vector<vertex>(col));

    for (int i = 0; i < row; ++i) {
      for (int j = 0; j < col; ++j) {
        cin >> graph[i][j].height;
      }
    }

    int sta_x, sta_y, ed_x, ed_y;
    cin >> sta_x >> sta_y >> ed_x >> ed_y;
    solve(sta_x-1, sta_y-1, ed_x-1, ed_y-1, row, col, graph);
  }
  return 0;
}

// dijkstra
void solve(int sta_x, int sta_y, int ed_x, int ed_y,
           int row, int col, vector<vector<vertex> >& graph) {
  vector<vector<int> > dist(row, vector<int>(col, INF));
  int count = 1, x = sta_x, y = sta_y;

  dist[sta_x][sta_y] = 0;


  while (count++ < row*col) { // there is an unknown dist vertex
    int minVertex = INF;

    // find the smallest unknown dist vertex
    for (int i = 0; i < row; ++i) {
      for (int j = 0; j < col; ++j) {
        if (!graph[i][j].known && dist[i][j] < minVertex) {
          x = i;
          y = j;
          minVertex = dist[i][j];
        }
      }
    }

    graph[x][y].known = true;

    for (int i = 0; i < 4; ++i) {
      int nextX = x + dir[i][0],
        nextY = y + dir[i][1];

      if (isValid(row, col, nextX, nextY) && !graph[nextX][nextY].known) {
        if (dist[x][y] + graph[nextX][nextY].height < dist[nextX][nextY]) {
          dist[nextX][nextY] = dist[x][y] + graph[nextX][nextY].height;
        }
      }
    }
  }

  cout << graph[sta_x][sta_y].height + dist[ed_x][ed_y] << endl;
}
