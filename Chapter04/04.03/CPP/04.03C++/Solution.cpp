#include "Solution.h"
#include <stack>
#include <map>
#include <vector>

using namespace std;

TreeNode* Tree::setRootValue(int value)
{
	if (m_root == NULL)
	{

		TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));

		root->setLeftNULL();
		root->setRightNULL();
		root->setParentNULL();
		root->setValue(value);

		m_root = root;
	}
	else
	{
		m_root->setValue(value);
	}

	return m_root;
}

TreeNode* Tree::insertLeftChild(int value, TreeNode* node)
{
	if (node == NULL)
		return NULL;

	TreeNode* child = (TreeNode*)malloc(sizeof(TreeNode));

	child->setLeftNULL();
	child->setRightNULL();
	child->setParent(node);
	child->setValue(value);

	node->setLeft(child);

	return child;
}

TreeNode* Tree::insertRightChild(int value, TreeNode* node)
{
	if (node == NULL)
	{
		return NULL;
	}

	TreeNode* child = (TreeNode*)malloc(sizeof(TreeNode));

	child->setLeftNULL();
	child->setRightNULL();
	child->setParent(node);
	child->setValue(value);

	node->setRight(child);

	return child;
}

void Tree::_freeTree(TreeNode* root)
{
	if (root == NULL)
	{
		return;
	}
	else
	{
		if (root->getLeft() != NULL)
		{
			_freeTree(root->getLeft());
		}

		if (root->getRight() != NULL)
		{
			_freeTree(root->getRight());
		}

		free(root);
	}
}



std::ostream& outputHelper(std::ostream& os, TreeNode* node)
{
	os << "(";
	if (node != NULL)
	{
		os << node->getValue();
		outputHelper(os, node->getLeft());
		outputHelper(os, node->getRight());
	}
	else
	{
		os << "*";
	}
	os << ")";
	return os;
}

std::ostream& operator << (std::ostream& os, Tree& t)
{
	return outputHelper(os, t.getRoot());
}

TreeNode* Tree::populateTreeFromSortedArray(int myArray[], int size)
{
	m_root=_constructHelper(myArray, 0, size - 1);

	return m_root;
}

TreeNode* Tree::_constructHelper(int myArray[], int start, int end)
{
	if (end < start)
	{
		return NULL;
	}

	int mid = (start + end) / 2;

	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
	node->setValue(myArray[mid]);

	node->setLeft(_constructHelper(myArray, start, mid - 1));
	node->setRight(_constructHelper(myArray, mid+1, end));
	
	return node;
}