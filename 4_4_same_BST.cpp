#include <iostream>
#include <vector>

using namespace std;
struct TreeNode {
  int val;
  TreeNode *left, *right;
  TreeNode(int v) : val(v), left(NULL), right(NULL) {}
};

class BST {
private:
  TreeNode* Rinsert(TreeNode *root, int value);
  void dele(TreeNode *root);
public:
  TreeNode *root;
  BST() : root(NULL) {}
  void insert(int value);
  ~BST();
};

void BST::insert(int value) {
  root = Rinsert(root, value);
}

TreeNode* BST::Rinsert(TreeNode *root, int value) {
  if (root == NULL) {
    root = new TreeNode(value);
  } else {
    if (value < root->val) {
      root->left = Rinsert(root->left, value);
    } else {
      root->right = Rinsert(root->right, value);
    }
  }

  return root;
}

BST::~BST() {
  dele(root);
}

void BST::dele(TreeNode *root) {
  if (root != NULL) {
    dele(root->left);
    dele(root->right);
    delete root;
  }
}


bool isSame(TreeNode *r1, TreeNode *r2) {
  if (!r1 && !r2)
    return true;
  if (!r1 || !r2)
    return false;
  if (r1->val != r2->val)
    return false;

  return isSame(r1->left, r2->left) && isSame(r1->right, r2->right);
}

int main() {
  int n, l;
  while (std::cin >> n && n) {
    std::cin >> l;
    // initial the target tree
    BST init;
    for (int i = 0; i < n; ++i) {
      int temp;
      std::cin >> temp;
      init.insert(temp);
    }

    // query
    while (l--) {
      BST comp;
      for (int i = 0; i < n; ++i) {
        int temp;
        std::cin >> temp;
        comp.insert(temp);
      }

      std::cout << (isSame(init.root, comp.root) ? "Yes\n" : "No\n");
    }
  }
}
