 #ifndef H_BinaryTree
#define H_BinaryTree

#include <cstddef>
#include <ostream>

template <class T>
struct BinaryTreeNode {
	T data;
	BinaryTreeNode* left;
	BinaryTreeNode* right;

	BinaryTreeNode() {
		left = NULL;
		right = NULL;
	}

	BinaryTreeNode(T value) {
		data = value;
		left = NULL;
		right = NULL;
	}
};



template <class T>
class BinaryTree {

protected:
	BinaryTreeNode<T>* root;
	int size;

public:
	BinaryTree();
	BinaryTree(const BinaryTree& other);
	BinaryTree<T>& operator=(const BinaryTree<T>& other);
	BinaryTreeNode<T>* getRoot() const;
	~BinaryTree();
	BinaryTreeNode<T>* copyTree(BinaryTreeNode<T>* node);
	void deleteTree(BinaryTreeNode<T>* node);
	std::string toStringInOrder(BinaryTreeNode<T>* node) const;
	std::string toStringInOrder() const;
	void insert(T value);
	void insert(BinaryTreeNode<T>* node, T value);
	bool find(const T& value) const;
	bool find(BinaryTreeNode<T>* node, const T& value) const;
	//friend std::ostream& operator <<(std::ostream & out, const BinaryTree<T>& tree);
};

template <class T>
BinaryTree<T>::BinaryTree() {
	root = NULL;
	size = 0;
}

template <class T>
std::string BinaryTree<T>::toStringInOrder(BinaryTreeNode<T>* node) const {

	std::string traversal;
	if (node == NULL) {
		return traversal;
	}
	//traverse left
	traversal = toStringInOrder(node->left);
	//visit current
	traversal += (node->data);
	//traverse right
	traversal += toStringInOrder(node->right);
	return traversal;
}

template <class T>
std::string BinaryTree<T>::toStringInOrder() const {
	return toStringInOrder(root);
}

template <class T>
BinaryTreeNode<T>* BinaryTree<T>::getRoot() const {
	return root;
}

template <class T>
void BinaryTree<T>::insert(BinaryTreeNode<T>* node, T value) {
	bool left = value < node->data;
	if (left) { //go left
		if (node->left) {
			insert(node->left, value);
		}
		else { //empty
			node->left = new BinaryTreeNode<T>(value);
		}
	}
	else { //go right
		if (node->right) {
			insert(node->right, value);
		}
		else { //empty
			node->right = new BinaryTreeNode<T>(value);
		}
	}
}

template <class T>
void BinaryTree<T>::insert(T value) {
	if (root) {
		insert(root, value);
	}
	else {
		root = new BinaryTreeNode<T>(value);
	}
	size++;
}

/*
template <class T>
std::ostream& operator <<(std::ostream & out, const BinaryTree<T>& tree){
out << tree.toStringInOrder();
}
*/

template <class T>
BinaryTree<T>::BinaryTree(const BinaryTree<T>& other) {
	root = copyTree(other.root);
	size = other.size;
}

template <class T>
BinaryTreeNode<T>* BinaryTree<T>::copyTree(BinaryTreeNode<T>* node) {
	/*if (node == NULL) {
	return NULL;
	}*/
	BinaryTreeNode<T>* copy = NULL;
	if (node) {
		copy = new BinaryTreeNode<T>(node->data);
		copy->left = copyTree(node->left);
		copy->right = copyTree(node->right);
	}
	return copy;

}

template <class T>
BinaryTree<T>& BinaryTree<T>::operator=(const BinaryTree<T>& other) {
	BinaryTreeNode<T>* temp = root;
	root = copyTree(other.root);
	size = other.size;
	deleteTree(temp);
	return *this;
}

template <class T>
BinaryTree<T>::~BinaryTree() {
	deleteTree(root);
	root = NULL;

}

template <class T>
void BinaryTree<T>::deleteTree(BinaryTreeNode<T>* node) {
	if (node) {
		deleteTree(node->left);
		deleteTree(node->right);
		delete node;
	}

}

template <class T>
bool BinaryTree<T>::find(BinaryTreeNode<T>* node, const T& value) const {
	bool retVal = false;
	if (node) {
		if (value == node->data) {
			retVal = true;
		}
		else if (value < node->data) {
			retVal = find(node->left, value);
		}
		else {
			retVal = find(node->right, value);
		}
	}

	return retVal;
}

template <class T>
bool BinaryTree<T>::find(const T& value) const {
	return find(root, value);
}

#endif
