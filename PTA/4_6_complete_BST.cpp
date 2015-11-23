#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
vector<int> rlist;
vector<int> tree;
int index;
void create_tree(int root) {
  if (root > n) return;
  int lchild = root<<1, rchild = (root<<1) + 1;
  create_tree(lchild);
  tree[root] = rlist[index++];
  create_tree(rchild);
}

int main() {
  index = 0;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int temp;
    cin >> temp;
    rlist.push_back(temp);
  }
  sort(rlist.begin(), rlist.end());

  tree.assign(n+1, 0);
  create_tree(1);

  // print answer in level order
  bool isfirst = true;
  for (int i = 1; i <= n; ++i) {
    if (isfirst) isfirst = false;
    else std::cout << " ";

    std::cout << tree[i];
  }
  std::cout << std::endl;

  return 0;
}
