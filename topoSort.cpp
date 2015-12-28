/**
 * @Author: zhuangqh
 * @Email: zhuangqhc@gmail.com
 * @Create on: 2015-12-28 16:36:45
 */

#include <iostream>
#include <vector>
#include <queue>

template <typename T>
struct Vertex {
  T val;
  int indegree;
  Vertex(T v, int indg = 0): val(v), indegree(indg) {}
};

// @param eage : aajacency list
// @param v: vertex list
// @param n: numbers of vertex
template <typename T>
void topoSort(std::vector<std::vector<int> >& eage,
              std::vector<Vertex<T> >& v, int n) {
  std::queue<int> buf;
  std::vector<Vertex<T> > result;
  int count = 0;

  for (int i = 0; i < v.size(); ++i) {
    if (!v.indegree) {
      buf.push(i);
      result.push_back(v[i]);
      count++;
    }
  }

  while (!buf.empty()) {
    int cur = buf.front();
    buf.pop();

    for (std::vector<int>::iterator it = eage[cur].begin();
         it != eage[cur].end(); it++) {

      if (--v[*it].indegree == 0) {
        buf.push(*it);
        result.push_back(v[*it]);
      }
    }
  }

  // check if topoSortable and print result
  if (count != n) {
    std::cout << "Impossible\n";
  } else {
    for (int i = 0; i < result.size(); ++i) {
      std::cout << result[i].val << " ";
    }
    std::cout << std::endl;
  }
}


int main() {
  return 0;
}
