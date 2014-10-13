#ifndef _SOLUTION_H
#define _SOLUTION_H

#include <iostream>

class TreeNode;
class TreeNode
{
public:
	TreeNode(char value = ' ') :m_value(value){ m_left = NULL; m_right = NULL; m_parent = NULL; }
	
	TreeNode* getParent(){ return m_parent; }
	TreeNode* getLeft(){ return m_left; }
	TreeNode* getRight(){ return m_right; }
	char getValue(){ return m_value; }

	void setLeft(TreeNode* left){ m_left = left; }
	void setRight(TreeNode* right){ m_right = right; }
	void setParent(TreeNode* parent){ m_parent = parent; }
	void setLeftNULL(){ m_left = NULL; }
	void setRightNULL(){ m_right = NULL; }
	void setParentNULL(){ m_parent = NULL; }
	void setValue(char value){ m_value = value; }
private:
	char m_value;
	TreeNode* m_left;
	TreeNode* m_right;
	TreeNode* m_parent;
};

class Tree;
class Tree
{
	friend std::istream& operator >> (std::istream& is, Tree& t);
	friend std::ostream& operator << (std::ostream& is, Tree& t);
public:
	Tree(){ m_root = NULL; }
	Tree(char value){ setRootValue(value); }
	~Tree(){ _freeTree(m_root); };

	TreeNode* getRoot(){ return m_root; }

	TreeNode* setRootValue(char value);
	TreeNode* insertLeftChild(char value, TreeNode* node);
	TreeNode* insertRightChild(char value, TreeNode* node);

	bool isBalanced(){ return _balanceHelper(m_root); }
private:
	TreeNode* m_root;
	void _freeTree(TreeNode*);
	bool _balanceHelper(TreeNode* node);
};

#endif