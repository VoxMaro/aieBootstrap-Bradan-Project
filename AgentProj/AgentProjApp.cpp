#include "AgentProjApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"

AgentProjApp::AgentProjApp() {

}

AgentProjApp::~AgentProjApp() {

}

bool AgentProjApp::startup() {
	
	m_2dRenderer = new aie::Renderer2D();
	m_font = new aie::Font("./font/consolas.ttf", 32);

	return true;
}

void AgentProjApp::shutdown() {

	delete m_font;
	delete m_2dRenderer;
}

void AgentProjApp::update(float deltaTime) {

	// input example
	aie::Input* input = aie::Input::getInstance();

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void AgentProjApp::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	// draw your stuff here!
	
	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);

	// done drawing sprites
	m_2dRenderer->end();
}