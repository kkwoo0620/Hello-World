#include<iostream>
#include"BinaryTree.h"
using namespace std;

void print(int data);

int main()
{
	BTreeNode * bt1 = MakeBTreeNode();
	BTreeNode * bt2 = MakeBTreeNode();
	BTreeNode * bt3 = MakeBTreeNode();
	BTreeNode * bt4 = MakeBTreeNode();

	SetData(bt1, 1);
	SetData(bt2, 2);
	SetData(bt3, 3);
	SetData(bt4, 4);

	MakeLeftSubTree(bt1, bt2);
	MakeRightSubTree(bt1, bt3);
	MakeLeftSubTree(bt2, bt4);

	InorderTraverse(bt1, print);
	cout << endl;
	PreorderTraverse(bt1, print);
	cout << endl;
	PostorderTraverse(bt1, print);
	cout << endl;

	DeleteTree(bt1);

	return 0;
}

void print(int data)
{
	cout << data << ' ';
}