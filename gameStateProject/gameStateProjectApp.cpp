#include "gameStateProjectApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"

gameStateProjectApp::gameStateProjectApp() {

}

gameStateProjectApp::~gameStateProjectApp() {

}

bool gameStateProjectApp::startup() {
	
	m_2dRenderer = new aie::Renderer2D();
	m_font = new aie::Font("./font/consolas.ttf", 32);
	m_GameStateManager = GameStateManager(4);
	m_GameStateManager.registerState(0, new SplashState() );
	m_GameStateManager.registerState(1, new MenuState());
	m_GameStateManager.registerState(2, new PlayState());
	m_GameStateManager.registerState(3, new PauseState());

	return true;
}

void gameStateProjectApp::shutdown() {

	delete m_font;
	delete m_2dRenderer;
}

void gameStateProjectApp::update(float deltaTime) {

	// input example
	

	while (m_GameStateManager.activeStateCount > 0) {
		aie::Input* input = aie::Input::getInstance();
		m_GameStateManager.update(deltaTime);
		if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
			quit();
	}

	quit();



	// exit the application
	
}


void gameStateProjectApp::draw() {
	while (m_GameStateManager.activeStateCount > 0) {
		clearScreen();
		m_2dRenderer->begin();
		m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);
		m_GameStateManager.draw;
		m_2dRenderer->end();
	}
	// wipe the screen to the background colour
	

	// begin drawing sprites
	

	// draw your stuff here!
	
	// output some text, uses the last used colour
	

	// done drawing sprites
	
}