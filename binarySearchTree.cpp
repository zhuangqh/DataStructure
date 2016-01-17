// create on 2016-01-17

template <class Entry>
struct Node {
	Entry entry;
	Node<Entry> *left, *right;
	Node(const Entry& en) {
		entry = en;
		left = right = NULL;
	}
};

template <typename Entry>
Node<Entry>* BSTree_search(Node<Entry>* root, Entry& target) {
	if (!root || root->entry == target) {
		return root;
	} else if (target < root->entry) {
		return BSTree_search(root->left, target);
	} else {
		return BSTree_search(root->right, target);
	}
}

template <typename Entry>
void BSTree_insert(Node<Entry>*& root, const Entry& target) {
	if (!root) {
		root = new Node<Entry>(target);
	} else if (target < root->entry) {
		BSTree_insert(root->left, target);
	} else if (target > root->entry) {
		BSTree_insert(root->right, target);
	}
}

template <typename Entry>
Node<Entry>* findMax(Node<Entry>* root) {
	if (root == NULL)
		return NULL;
	while (root->right) {
		root = root->right;
	}
	return root;
}

template <typename Entry>
void BSTree_remove(Node<Entry>*& root, const Entry& target) {
	if (root == NULL) {
		return;
	} else if (target < root->entry) {
		BSTree_remove(root->left, target);
	} else if (target > root->entry) {
		BSTree_remove(root->right, target);
	} else if (root->left && root->right) {
		root->entry = findMax(root->left)->entry;
		BSTree_remove(root->left, root->entry);
	} else {
		Node<Entry>* toDelete = root;
		root = (root->left ? root->left : root->right);
		delete toDelete;
	}
}


