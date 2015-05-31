#include <iostream>
#include <string>
struct instructions {
  int _mode, _data;
  instructions() : _mode(-1), _data(-1) {}
};
struct node {
  int _data;
  node *left, *right, *pre;
  bool is_visited;
  node(int data, node *p) {
    _data = data;
    left = right = NULL;
    pre = p;
    is_visited = false;
  }
};
instructions ins_table[100];
bool is_first = true;
void post_order_traversal(node *);
void destroy(node *);
int main() {
  int t;
  std::cin >> t;
  //read and save the instructions
  for (int i = 0; i < 2 * t; ++i) {
    std::string ins;
    int data;
    std::cin >> ins;
    if (ins == "Push") {
      ins_table[i]._mode = 0;
      std::cin >> data;
      ins_table[i]._data = data;
    } else {
      ins_table[i]._mode = 1;
    }
  }
  //generate a binary tree from the stack record
  node *root = new node(ins_table[0]._data, NULL);
  node *ptr = root;
  for (int i = 1; i < 2*t; ++i) {
    if (ins_table[i]._mode == 0) {

      node *new_node = new node(ins_table[i]._data, ptr);

      if (ptr->left == NULL) {
        ptr->left = new_node;
      } else {
        ptr->right = new_node;
      }
      ptr = new_node;

    } else {

      while (ptr->is_visited == true) {
        ptr = ptr->pre;
      }
      ptr->is_visited = true;

    }

  }
  //print the answer in post order
  post_order_traversal(root);
  std::cout << std::endl;
  //deallocate memory
  destroy(root);
  return 0;
}

void post_order_traversal(node *root) {
  if (root) {
    post_order_traversal(root->left);
    post_order_traversal(root->right);
    if (is_first) is_first = false;
    else std::cout << ' ';
    std::cout << root->_data;
  }
}
void destroy(node *root) {
  if (root) {
    destroy(root->left);
    destroy(root->right);
    delete root;
  }
}
