/**
 * @Author: zhuangqh
 * @Email: zhuangqhc@gmail.com
 * @Create on: 2015-12-21 11:37:02
 */

#include <iostream>
#include <algorithm>

#ifndef AVL_NODE
#define AVL_NODE
template <class Entry>
struct AvlNode {
    Entry entry;
    AvlNode<Entry> *left;
    AvlNode<Entry> *right;
    int height;
    AvlNode(Entry e): entry(e), left(NULL), right(NULL), height(0) {}
};
#endif

template <typename T>
int Height(AvlNode<T>* node) {
  return node ? node->height : 0;
}

template <typename T>
void RightRotate(AvlNode<T>*& parent) {
  AvlNode<T>* child = parent->left;
  parent->left = child->right;
  child->right = parent;
  parent->height = std::max(Height(parent->left), Height(parent->right)) + 1;
  child->height = std::max(Height(child->left), Height(child->right)) + 1;
  parent = child;
}

template <typename T>
void LeftRotate(AvlNode<T>*& parent) {
  AvlNode<T>* child = parent->right;
  parent->right = child->left;
  child->left = parent;
  parent->height = std::max(Height(parent->left), Height(parent->right)) + 1;
  child->height = std::max(Height(child->left), Height(child->right)) + 1;
  parent = child;
}

template <typename T>
void LeftRightRotate(AvlNode<T>*& parent) {
  LeftRotate(parent->left);
  RightRotate(parent);
}

template <typename T>
void RightLeftRotate(AvlNode<T>*& parent) {
  RightRotate(parent->right);
  LeftRotate(parent);
}

template <typename T>
void AVL_insert(AvlNode<T>*& root, const T x) {
  if(root == NULL) {
    root = new AvlNode<T>(x);
  } else if(x < root->entry) {
    AVL_insert(root->left, x);
    if(Height(root->left) - Height(root->right) == 2) {
      if(x < root->left->entry) {
       RightRotate(root);
      } else {
        LeftRightRotate(root);
      }
    }
  } else if (x > root->entry) {
    AVL_insert(root->right, x);
    if(Height(root->right) - Height(root->left) == 2) {
      if(x > root->right->entry) {
        LeftRotate(root);
      } else {
        RightLeftRotate(root);
      }
    }
  }
  root->height = std::max(Height(root->left), Height(root->right)) + 1;
}


template <typename T>
AvlNode<T>* AVL_search(AvlNode<T>*& root, const T entry) {
  if (root == NULL) return NULL;
  if (entry == root->entry) {
      return root;
  } else if (entry < root->entry) {
      return AVL_search(root->left);
  } else {
      return AVL_search(root->right);
  }
}

template <typename T>
void print(AvlNode<T>* root) {
	if (root == NULL) return;
	std::std::cout << root->entry << " ";
	print(root->left);
	print(root->right);
}

// test
int main() {
	AvlNode<int>* root = NULL;
	AVL_insert(root, 1);
	print(root);
	std::cout << std::endl;
	AVL_insert(root, 2);
	print(root);
	std::cout << std::endl;
	AVL_insert(root, 5);
	print(root);
	std::cout << std::endl;
	AVL_insert(root, 4);
	print(root);
	std::cout << std::endl;
	AVL_insert(root, 3);
	print(root);
	std::cout << std::endl;
}