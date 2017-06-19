#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "BinaryTree.h"


class BinaryTreeProjApp : public aie::Application {
public:

	BinaryTreeProjApp();
	virtual ~BinaryTreeProjApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	aie::Renderer2D*	m_2dRenderer;
	BinaryTree m_binaryTree;
	TreeNode* m_selectedNode;
	//aie::Font*			m_font;
};