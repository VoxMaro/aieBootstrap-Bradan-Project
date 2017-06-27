#pragma once
#include "GameState.h"

class PlayState : public GameState {
public:
	PlayState(GameStateProjectApp *pApp);
	virtual ~PlayState() {}

	virtual void onUpdate(float deltaTime);
	virtual void onDraw();
};
