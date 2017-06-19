#include "BinaryTreeProjApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "imgui.h"
//#include <imgui>

namespace aie {
	class Texture;
}


aie::Font* g_systemFont = nullptr;

BinaryTreeProjApp::BinaryTreeProjApp() {

}

BinaryTreeProjApp::~BinaryTreeProjApp() {

}

bool BinaryTreeProjApp::startup() {
	
	m_2dRenderer = new aie::Renderer2D(); 
	g_systemFont = new aie::Font("./font/consolas.ttf", 32); 

	return true;
}

void BinaryTreeProjApp::shutdown() {

	//delete m_font;
	delete m_2dRenderer;
}

void BinaryTreeProjApp::update(float deltaTime) {
	
	// input example
	aie::Input* input = aie::Input::getInstance();

	static int value = 0;
	ImGui::InputInt("Value", &value);

	if (ImGui::Button("Insert", ImVec2(50, 0)))
	{
		m_binaryTree.insert(value);
		m_selectedNode = m_binaryTree.find(value);
	}

	if (ImGui::Button("Remove", ImVec2(50, 0)))
	{
		m_binaryTree.remove(value);
	}
	if (ImGui::Button("Find", ImVec2(50, 0)))
	{
		m_selectedNode = m_binaryTree.find(value);
	}
	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void BinaryTreeProjApp::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	// draw your stuff here!
	m_binaryTree.draw(m_2dRenderer, m_selectedNode);
	// output some text, uses the last used colour
	m_2dRenderer->drawText(g_systemFont, "Press ESC to quit", 0, 0);

	// done drawing sprites
	m_2dRenderer->end();
}