#pragma once

namespace aie {
	class Renderer2D;
}

class TreeNode {
public:
	TreeNode(int val);
	~TreeNode();

	bool hasLeft() { return (m_left != nullptr); }
	bool hasRight() { return (m_right != nullptr); }

	int getData() { return m_value; }
	TreeNode* getLeft() { return m_left; }
	TreeNode* getRight() { return m_right; }

	void setData(int value) { m_value = value; }
	void setLeft(TreeNode* node) { m_left = node; }
	void setRight(TreeNode* node) { m_right = node; }
	void draw(aie::Renderer2D* render, int x, int y, bool selected = false);
private:
	int m_value;

	TreeNode* m_left;
	TreeNode* m_right;
};