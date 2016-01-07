/**
 * @Author: zhuangqh
 * @Email: zhuangqhc@gmail.com
 * @Create on: 2016-01-07 20:46
 */

#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

struct node {
  int x, y;
  int step;
  node(int xx = 0, int yy = 0, int s = 0): x(xx), y(yy), step(s) {}
  bool operator==(node& other) {
    return other.x == this->x && other.y == this->y;
  }
};

bool isValid(int x, int y) {
  return x >= 0 && x < 8 && y >= 0 && y < 8;
}

const int dir[8][2] = {{-1, -2}, {-1, 2}, {1, -2}, {1, 2},
                       {-2, -1}, {-2, 1}, {2, -1}, {2, 1}};

node sta, ed;

int bfs(vector<vector<bool> >& visit) {
  queue<node> buf;
  buf.push(sta);
  visit[sta.x][sta.y] = true;

  while (!buf.empty()) {
    node tmp = buf.front();
    buf.pop();

    if (tmp == ed) {
      return tmp.step;
    }

    for (int i = 0; i < 8; ++i) {
      int x = tmp.x + dir[i][0],
        y = tmp.y + dir[i][1];
      if (isValid(x, y) && !visit[x][y]) {
        buf.push(node(x, y, tmp.step + 1));
        visit[x][y] = true;
      }
    }
  }
  return 0;
}


int main() {
  int n;
  cin >> n;
  while (n--) {
    vector<vector<bool> > visit(8, vector<bool>(8, false));
    string ssta, send;
    cin >> ssta;
    sta.x = ssta[0] - 'a';
    sta.y = ssta[1] - '1';
    cin >> send;
    ed.x = send[0] - 'a';
    ed.y = send[1] - '1';

    // cout << sta.x << " " << sta.y << endl
    //     << ed.x << " " << ed.y << endl;
    cout << "To get from " + ssta + " to " + send + " takes " << bfs(visit)
         << " knight moves.\n";
  }

  return 0;
}
