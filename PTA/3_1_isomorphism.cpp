#include <iostream>
#include <vector>

struct TreeNode {
  char val;
  int left, right;
  TreeNode(char v, int l, int r) : val(v), left(l), right(r) {}
};

std::vector<TreeNode> vec1;
std::vector<TreeNode> vec2;

bool judge(int root1, int root2) {
  if (root1 == ('-'-'0') && root2 == ('-'-'0'))
    return true;

  if (root1 == ('-'-'0') || root2 == ('-'-'0'))
    return true;

  if (vec1[root1].val != vec2[root2].val)
    return false;

  return (judge(vec1[root1].left, vec2[root2].left) &&
          judge(vec1[root1].right, vec2[root2].right)) ||
    (judge(vec1[root1].left, vec2[root2].right) &&
     (judge(vec1[root1].right, vec2[root2].left)));
}
int main() {
  int root1 = 0, root2 = 0;
  int size1, size2;

  // Tree1
  std::cin >> size1;
  for (int i = 0; i < size1; ++i) {
    root1 ^= i;
    char v, l, r;
    std::cin >> v >> l >> r;

    vec1.push_back(TreeNode(v, l-'0', r-'0'));

    if (l != '-')
      root1 ^= (l - '0');
    if (r != '-')
      root1 ^= (r - '0');

  }

  // Tree2
  std::cin >> size2;
  for (int i = 0; i < size2; ++i) {
    char v, l, r;
    std::cin >> v >> l >> r;

    vec2.push_back(TreeNode(v, l-'0', r-'0'));

    if (l != '-')
      root2 ^= (l - '0');
    if (r != '-')
      root2 ^= (r - '0');
  }
  //std::cout << "root is " << root1 << " " << root2 << std::endl;
  if (vec1.empty() && vec2.empty()) {
    std::cout << "Yes\n";
  } else {
    std::cout << (judge(root1, root2) ? "Yes\n" : "No\n");
  }
  return 0;
}
