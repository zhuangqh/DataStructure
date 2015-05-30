#include <iostream>
#include <string>
struct instructions {
  int _mode, _data;
  instructions() : _mode(-1), _data(-1) {}
};
struct node {
  int _data;
  node *left, *right;
  node(int data) : _data(data), left(NULL), right(NULL) {}
  node() : _data(-1), left(NULL), right(NULL) {}
};
instructions ins_table[100];
int main() {
  int t;
  std::cin >> t;
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

    node* root = new node(ins_table[0]._data);
    node* pre = root, *post = (root->left);
    for (int i = 1; i < 2 * t; ++i) {
      if (ins_table[i]._mode == 0) {

      }
    }
  }
  return 0;
}
