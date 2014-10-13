#include "Solution.h"
#include <stack>
#include <map>

using namespace std;

TreeNode* Tree::setRootValue(char value)
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

TreeNode* Tree::insertLeftChild(char value, TreeNode* node)
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

TreeNode* Tree::insertRightChild(char value, TreeNode* node)
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

/*
std::istream& inputHelper(std::istream& is, TreeNode* node)
{
	char c;
	stack<TreeNode*>parentStack;

	while (is >> c)
	{
		if (c == '(')
		{
			parentStack.push(node);
		}
		else if (c == '*')
		{
			continue;
		}
		else if (c == ')')
		{
			parentStack.push(node);
		}
		else
		{
			if (parentStack.empty())
			{
				TreeNode* root = parentStack.top();
			}
		}
		
	}
	return is;
}
*/

std::istream& operator >> (std::istream& is, Tree& t)
{
	char c;
	stack<TreeNode*>parentStack;
	map<TreeNode*, bool> leftDone;
	map<TreeNode*, bool> rightDone;

	TreeNode* node = t.getRoot();
	while (is >> c)
	{
		if (c == '(')
		{
			parentStack.push(node);
			if (leftDone[node] == true)
			{
				parentStack.pop();
			}
		}
		else if (c == '*')
		{
			if (parentStack.empty())
			{
				continue;
			}
			else
			{
				TreeNode* temp = parentStack.top();
				if (!leftDone[temp])
				{
					leftDone[temp] = true;
				}
				else if (!rightDone[temp])
				{
					rightDone[temp] = true;
				}
			}
		}
		else if (c == ')')
		{
			if (parentStack.empty())
			{
				return is;
			}
			else
			{
				TreeNode* temp = parentStack.top();
				if (rightDone[temp] == true)
				{
					parentStack.pop();
				}
			}
		}
		else
		{
			TreeNode* temp = parentStack.top();

			if (temp == NULL)
			{
				node = t.setRootValue(c);
				parentStack.pop();
			}
			else 
			{
				if (leftDone[temp] == false)
				{
					node = t.insertLeftChild(c, temp);
					leftDone[temp] = true;
				}
				else
				{
					node = t.insertRightChild(c, temp);
					rightDone[temp] = true;
				}
			}
		}
	}
	return is;
}


std::ostream& outputHelper(std::ostream& os, TreeNode* node)
{
	os << "(";
	if (node!=NULL)
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

bool Tree::_balanceHelper(TreeNode* node)
{
	if (node == NULL)
	{
		return true;
	}
	else if (node->getLeft() == NULL)
	{
		if (node->getRight() == NULL)
		{
			return true;
		}
		else if (node->getRight()->getLeft() == NULL && node->getRight()->getRight() == NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else if (node->getRight() == NULL)
	{
		if (node->getLeft() == NULL)
		{
			return true;
		}
		else if (node->getLeft()->getLeft() == NULL && node->getLeft()->getRight() == NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return _balanceHelper(node->getLeft()) && _balanceHelper(node->getRight());
	}
}