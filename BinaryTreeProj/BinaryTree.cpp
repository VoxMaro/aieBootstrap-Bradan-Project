#include "BinaryTree.h"
#include "TreeNode.h"
#include <Renderer2D.h>
#include <Font.h>
#include <string>




BinaryTree::BinaryTree()
{
	m_pRoot = nullptr;
}

BinaryTree::~BinaryTree()
{
	while (m_pRoot)
	{
		remove(m_pRoot->getData());
	}
}

//binarytree
void BinaryTree::draw(aie::Renderer2D* renderer, TreeNode* selected)
{
	draw(renderer, m_pRoot, 640, 680, 640, selected);
}

void BinaryTree::draw(aie::Renderer2D* renderer, TreeNode* pNode, int x, int y, int horizontalSpacing, TreeNode* selected)
{
	horizontalSpacing /= 2;
	if (pNode) { 
		if (pNode->hasLeft()) {
			renderer->setRenderColour(1, 0, 0);
			renderer->drawLine(x, y, x - horizontalSpacing, y - 80);
			draw(renderer, pNode->getLeft(), x - horizontalSpacing, y - 80, horizontalSpacing, selected); 
		}

		if (pNode->hasRight()) { 
			renderer->setRenderColour(1, 0, 0);
			renderer->drawLine(x, y, x + horizontalSpacing, y - 80);
			draw(renderer, pNode->getRight(), x + horizontalSpacing, y - 80, horizontalSpacing, selected);
		} 

		pNode->draw(renderer, x, y, (selected == pNode)); 
	}
}


bool BinaryTree::isEmpty() const
{
	 return !m_pRoot;
}

void BinaryTree::insert(int a_nValue)
{
	TreeNode* parNode = nullptr;
	if (isEmpty())
	{
		m_pRoot = new TreeNode(a_nValue);
	}
	else {
		TreeNode* curNode;
		curNode = m_pRoot;
		
		while (curNode != nullptr) {
			parNode = curNode;
			if (a_nValue > curNode->getData()){
				curNode = curNode->getRight();
			}
			else if (a_nValue < curNode->getData()) {
				curNode = curNode->getLeft();
			}
			else if (a_nValue == curNode->getData()) {
				break;
			}
		}
		if (a_nValue > parNode->getData())
			parNode->setRight(new TreeNode(a_nValue));
		else
			parNode->setLeft(new TreeNode(a_nValue));
		
	}
}

bool BinaryTree::findNode(int a_nSearchValue, TreeNode** ppOutNode, TreeNode** ppOutParent)
{
	*ppOutNode = nullptr;
	*ppOutParent = nullptr;

	if (isEmpty())
	{
		return false;
	}

	TreeNode* curNode = m_pRoot;
	TreeNode* parNode = nullptr;

	while (curNode)
	{
		if (a_nSearchValue == curNode->getData())
		{

			*ppOutNode = curNode;
			*ppOutParent = parNode;
			return true;
		}
		else {
			parNode = curNode;
			if (curNode->getData() > a_nSearchValue)
				curNode = curNode->getLeft();
			else if (curNode->getData() < a_nSearchValue)
				curNode = curNode->getRight();
		}

	}
}


void BinaryTree::remove(int value) {
	TreeNode* remNode;
	TreeNode* remParNode;
	
	findNode(value, &remNode, &remParNode);
	if (remNode) {
		if (remNode->hasRight()) {
			TreeNode* minNode = remNode->getRight();
			TreeNode* parMinNode = remNode;
			minNode = remNode->getRight();
			while (minNode->hasLeft()) {
				parMinNode = minNode;
				minNode = minNode->getLeft();
			}
			remNode->setData(minNode->getData());


			if (minNode == parMinNode->getLeft())
				parMinNode->setLeft(minNode->getRight());
			else
				parMinNode->setRight(minNode->getRight());
			delete minNode;
		}
		else {
			if (remParNode) {
				if (remNode == remParNode->getLeft()) {
					remParNode->setLeft(remNode->getLeft());
				}
				if (remNode == remParNode->getRight())
					remParNode->setRight(remNode->getLeft());
				if (!remParNode) {
					m_pRoot = remNode->getLeft();
				}
			}
			else { m_pRoot = nullptr; }
			delete remNode;

		}
	}



}

TreeNode * BinaryTree::find(int a_nValue)
{
	TreeNode* pCurrent = nullptr;
	TreeNode* pParent = nullptr;

	return findNode(a_nValue, &pCurrent, &pParent) ? pCurrent : nullptr;
}








//treenode

