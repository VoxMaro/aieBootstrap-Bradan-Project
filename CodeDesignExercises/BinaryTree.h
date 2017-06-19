#pragma once
#include "TreeNode.h"

namespace aie {
	class Renderer2D;
}

class BinaryTree {
	//struct Node;
public:
	BinaryTree();
	~BinaryTree();

	bool isEmpty() const;
	void insert(int a_nValue);
	void remove(int a_nValue);
	TreeNode* find(int a_nValue);

	void draw(aie::Renderer2D* renderer, TreeNode* selected = nullptr);

private:
	bool findNode(int a_nSearchValue, TreeNode** ppOutNode, TreeNode** ppOutParent);
	void draw(aie::Renderer2D* renderer, TreeNode* pNode, int x, int y, int horizontalSpacing, TreeNode* selected = nullptr);

	TreeNode* m_pRoot;
};

