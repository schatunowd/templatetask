#include<vector>
#include<iostream>
#include<string>
using namespace std;

template<class T>
class BinaryTree
{
public:
	BinaryTree():node(nullptr) {}
	~BinaryTree();
	void addvertex(T);
	void deletevertex(T);
	bool contains(T);
	vector<T> getleaflist();
	operator string();

private:
	struct Node
	{
		T data;
		Node* leftchild;
		Node* rightchild;
		Node(T _data) :data(_data), leftchild(nullptr), rightchild(nullptr) {}
	};
	Node* node;
	void dispose(Node*);
	void addvertex(T, Node*&);
	void deletevertex(T, Node*&);
	bool contains(T, Node*);
	void getleaflist(Node*, vector<T>&);
	string binarytreestring(Node*);
};

template<class T>
BinaryTree<T>::~BinaryTree()
{
	if (node)
		this->dispose(this->node);
}

template<class T>
void BinaryTree<T>::dispose(Node* root)
{
	if (root)
	{
		dispose(root->left);
		dispose(root->right);
		delete root;
	}
}

template<class T>
void BinaryTree<T>::addvertex(T data)
{
	if (node == nullptr)
	{
		node = new Node(data);
	}
	else
	{
		this->addvertex(data, node);
	}
}

template<class T>
void BinaryTree<T>::addvertex(T data, Node*& node)
{
	if (node == nullptr)
		node = new Node(data);
	else
		if (data < node->data)
			this->add(data, node->left);
		else
			if (data > node->data)
				this->add(data, node->right);
}

template<class T>
string BinaryTree<T>::binarytreestring(Node* node) 
{
	string leftStr = (node->left == nullptr) ? "{}" : binarytreestring(node->left);
	string rightStr = (node->right == nullptr) ? "{}" : binarytreestring(node->right);
	string result = "{" + to_string(node->data) + ", " + leftStr + ", " + rightStr + "}";
	return result;
}

template<class T>
void BinaryTree<T>::deletevertex(T data)
{
	this->deletevertex(data, this->node);
}

template<class T>
void BinaryTree<T>::deletevertex(T data, Node*& root) 
{
	if (root == nullptr) 
		cout << "Not found";
	if (data > root->data) 
		del(data, root->right);
	else 
		if (data < root->data) 
			del(data, root->left);
		else
		{
			Node* temp = root;
			if (temp->right == nullptr && temp->left == nullptr)
				root = nullptr;
			else
				if (temp->right == nullptr && temp->left != nullptr)
					root = temp->left;
				else
					if (temp->left == nullptr && temp->right != nullptr)
						root = temp->right;
					else
					{
						Node* maxNode = temp->left;
						while (maxNode->right) maxNode = maxNode->right;
						temp->data = maxNode->data;
						del(maxNode->data, temp->left);
					}
		}
	   
}

template<class T>
bool BinaryTree<T>::contains(T data)
{
	return contains(data, node);
}

template<class T>
bool BinaryTree<T>::contains(T data, Node* root)
{
	if (root == nullptr) 
		return false;
	else 
		if (root->data == data) 
			return true;
	    else 
			if (data > root->data) 
				return contains(data, root->right);
	        else 
				return contains(data, root->left);
}

template<class T>
vector<T> BinaryTree<T>::getleaflist()
{
	vector<T> leafList;
	getleaflist(this->node, leafList);
	return leafList;
}

template<class T>
void BinaryTree<T>::getleaflist(Node* root, vector<T>& leaf)
{
	if (root->left == nullptr && root->right == nullptr)
	{
		leaf.push_back(root->data);
	}
	else
	{
		if (root->left) 
			getleaflist(root->left, leaf);
		else
			getleaflist(root->right, leaf);
	}
}

template<class T>
BinaryTree<T>::operator string()
{
	if (node == nullptr)
		return "{}";
	else 
		return this->binarytreestring(this->node);
}

int main()
{
	BinaryTree <int> binarytree;
	binarytree.addvertex(10);
	binarytree.addvertex(1);
	binarytree.addvertex(5);
	binarytree.addvertex(6);
	binarytree.addvertex(8);
	cout << "Your binary tree: ";
	binarytree.operator std::string;
	binarytree.deletevertex(10);
	if (binarytree.contains(12))
		binarytree.deletevertex(12);
	else
		cout << "Binary tree does not contain this element";
}