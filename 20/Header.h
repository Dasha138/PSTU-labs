#pragma once
#include <iostream>
using namespace std;
int k;
struct tree
{
	int data;
	tree* left;
	tree* right;
};
class btree
{
	tree* root;
	tree* insert(tree*& leaf, int element) 
	{
		if (leaf == NULL) 
		{
			tree* new_leaf = new tree;
			new_leaf->data = element;
			new_leaf->left = NULL;
			new_leaf->right = NULL;
			return new_leaf;
		}
		if (element < leaf->data)
			leaf->left = insert(leaf->left, element);
		if (element > leaf->data)
			leaf->right = insert(leaf->right, element);
		return leaf;
	}
	void print(tree* l)
	{
		if (l == NULL)
			return;
		cout << l->data << " ";
		print(l->left);
		print(l->right);
		k++;
	}
public:
	btree();
	~btree() { delete root; };
	void insert(int element) 
	{
		root = insert(root, element);
	}
	void print();
	void kol();
};
btree::btree()
{
	root = NULL;
}
void btree::print()
{
	print(root);
}
void btree::kol()
{
	cout << endl << "Кол-во: " << k << endl;
}