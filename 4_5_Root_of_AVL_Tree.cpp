#include <iostream>
#include <cmath>
struct node {
  int value;
  node *left, *right;
  int height;
  node(int v) : value(v), left(NULL), right(NULL), height(0) {}

};
int getHeight(node *n) {
  if (n == NULL) return -1;
  return n->height;
}

bool isBalanced(node *parent) {
  return std::abs(getHeight(parent->left) - getHeight(parent->right)) < 2;
}

class AVL_Tree {
 private:
  node *_root;
  node* rotate_LL(node *parent);
  node* rotate_RR(node *parent);
  node* rotate_LR(node *parent);
  node* rotate_RL(node *parent);
  node* insertNode(node*, int);
  void printTree(node *root) const;
  void dele(node *);
 public:
  AVL_Tree() : _root(NULL) {}
  void insert(int value);
  void print() const;
  int getRootValue() const;
  ~AVL_Tree();
};

int AVL_Tree::getRootValue() const {
  return _root->value;
}
node *AVL_Tree::rotate_LL(node *parent) {
  node *child = parent->left;
  parent->left = child->right;
  child->right = parent;

  parent->height = std::max(getHeight(parent->left),
                            getHeight(parent->right)) + 1;
  child->height = std::max(getHeight(child->left),
                           getHeight(child->right)) + 1;
  return child;
}
node* AVL_Tree::rotate_RR(node *parent) {
  node* child = parent->right;
  parent->right = child->left;
  child->left = parent;

  parent->height = std::max(getHeight(parent->left),
                            getHeight(parent->right)) + 1;
  child->height = std::max(getHeight(child->left),
                           getHeight(child->right)) + 1;
  return child;
}
node* AVL_Tree::rotate_LR(node *parent) {
  node *child = parent->left;
  parent->left = rotate_RR(child);
  return rotate_LL(parent);
}
node* AVL_Tree::rotate_RL(node *parent) {
  node *child = parent->right;
  parent->right = rotate_LL(child);
  return rotate_RR(parent);
}

void AVL_Tree::insert(int value) {
  _root = insertNode(_root, value);
}

node* AVL_Tree::insertNode(node *root, int value) {
  if (root == NULL) {
    root = new node(value);
  } else {
    if (value > root->value) {  //R
      root->right = insertNode(root->right, value);
      if (!isBalanced(root)) {
        if (value > root->right->value) {  //RR
          root = rotate_RR(root);
        } else {  //RL
          root = rotate_RL(root);
        }
      }
    } else {  //L
      root->left = insertNode(root->left, value);
      if (!isBalanced(root)) {
        if (value > root->left->value) {  //LR
          root = rotate_LR(root);
        } else {  //LL
          root = rotate_LL(root);
        }
      }
    }
  }
  root->height = std::max(getHeight(root->left),
                          getHeight(root->right)) + 1;
  return root;
}

void AVL_Tree::print() const {
  printTree(_root);
}

void AVL_Tree::printTree(node *root) const {
  if (root != NULL) {
    std::cout << root->value << "--";
    printTree(root->left);
    printTree(root->right);
  }
}

void AVL_Tree::dele(node *root) {
  if (root != NULL) {
    dele(root->left);
    dele(root->right);
    delete root;
  }
}
AVL_Tree::~AVL_Tree() {
  dele(_root);
}

int main() {
  int n;
  std::cin >> n;
  AVL_Tree avl;
  int num;
  for (int i = 0; i < n; ++i) {
    std::cin >> num;
    avl.insert(num);
  }
  std::cout << avl.getRootValue() << std::endl;
  return 0;
}
