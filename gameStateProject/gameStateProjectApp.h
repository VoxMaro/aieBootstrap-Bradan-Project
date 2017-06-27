#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "GameState.h"
#include "GameStateManager.h"

class gameStateProjectApp : public aie::Application {
public:

	gameStateProjectApp();
	virtual ~gameStateProjectApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	/*virtual void updateSplash(float deltaTime);
	virtual void updateMenu(float deltaTime);
	virtual void updateGame(float deltaTime);
	virtual void updatePause(float deltaTime);*/
	virtual void draw();

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;
	GameStateManager*	m_GameStateManager;
};