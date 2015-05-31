#include <iostream>
#include <queue>

int t;
int leave[10][2] = {0};
struct node {
  int data;
  node* left;
  node* right;
  node(int _data) : data(_data), left(NULL), right(NULL) {}
};
class BinTree {
 private:
  node* root;
 public:
  BinTree(int data) {
    generate_a_tree(data);
  }
  void generate_a_tree(int);
  void insert(node*);
  void print_the_tree();
  ~BinTree() {
    dele(root);
  }
  void dele(node*);
};

void BinTree::generate_a_tree(int _root) {
  root = new node(_root);
  insert(root);
}
void BinTree::insert(node *root) {
  int l = leave[root->data][0],
    r = leave[root->data][1];
  if (l != -1) {
    node* new_node = new node(l);
    root->left = new_node;
    insert(new_node);
  }
  if (r != -1) {
    node* new_node = new node(r);
    root->right = new_node;
    insert(new_node);
  }
}
void BinTree::print_the_tree() {
  bool is_first = true;
  std::queue<node*> buffer;
  if (root)
    buffer.push(root);
  node* p;
  while (!buffer.empty()) {
    p = buffer.front();
    buffer.pop();
    if (p->left == NULL && p->right == NULL) {
      if (is_first) is_first = false;
      else std::cout << ' ';
      std::cout << p->data;
    }
    if (p->left != NULL)
      buffer.push(p->left);
    if (p->right != NULL)
      buffer.push(p->right);
  }
  std::cout << std::endl;
}
void BinTree::dele(node* now) {
  if (now != NULL) {
    dele(now->left);
    dele(now->right);
    delete now;
  }
}


int main() {
  std::cin >> t;

  int root = 0;
  //read data and find the index of root
  for (int i = 0; i < t; ++i) {
    char l, r;
    std::cin >> l >> r;

    root ^= i;
    if (l == '-') {
      leave[i][0] = -1;
    } else {
      leave[i][0] = l - '0';
      root ^= (l - '0');
    }

    if (r == '-') {
      leave[i][1] = -1;
    } else {
      leave[i][1] = (r - '0');
      root ^= (r - '0');
    }
  }
  BinTree tree(root);
  tree.print_the_tree();
  return 0;
}
