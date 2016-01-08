/**
 * @Author: zhuangqh
 * @Email: zhuangqhc@gmail.com
 * @Create on: 2016-01-07 19:13
 */

#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

struct node {
  int val;
  node *left, *right;
  node(int v): val(v), left(NULL), right(NULL) {}
};

void insert(node*& root, int& val) {
  if (root == NULL) {
    root = new node(val);
  } else if (root->val >= val) {
    insert(root->left, val);
  } else {
    insert(root->right, val);
  }
}

/*
void preorder(node*& root) {
  stack<node*> s;
  node* p = root;
  while (p || !s.empty()) {
    if (p) {
      s.push(p);
      printf(" %d", p->val);
      p = p->left;
    } else {
      p = s.top();
      s.pop();
      p = p->right;
    }
  }
}

void inorder(node*& root) {
  stack<node*> s;
  node* p = root;
  while (p || !s.empty()) {
    if (p) {
      s.push(p);
      p = p->left;
    } else {
      p = s.top();
      s.pop();
      printf(" %d", p->val);
      p = p->right;
    }
  }
}

void postorder(node*& root) {
  stack<node*> s;
  node *p = root, *r;
  while (p || !s.empty()) {
    if (p) {
      s.push(p);
      p = p->left;
    } else {
      p = s.top();
      if (p->right && p->right != r) {
        p = p->right;
        s.push(p);
        p = p->left;
      } else {
        s.pop();
        printf(" %d", p->val);
        r = p;
        p = NULL;
      }
    }
  }
}
*/


void preorder(node*& root) {
  if (!root) return;
  printf(" %d", root->val);
  preorder(root->left);
  preorder(root->right);
}

void inorder(node*& root) {
  if (!root) return;
  inorder(root->left);
  printf(" %d", root->val);
  inorder(root->right);
}

void postorder(node*& root) {
  if (!root) return;
  postorder(root->left);
  postorder(root->right);
  printf(" %d", root->val);
}

int main() {
  int n;
  int tmp;
  bool first = true;
  while (cin >> n) {
    if (first) first = false;
    else cout << endl;

    node* root = NULL;
    for (int i = 0; i < n; ++i) {
      scanf("%d", &tmp);
      insert(root, tmp);
    }

    cout << "Inorder:";
    inorder(root);
    cout << "\nPreorder:";
    preorder(root);
    cout << "\nPostorder:";
    postorder(root);
    cout << endl;
  }

  return 0;
}
