#pragma once
class GameStateProjectApp;

class GameState {
	//friend class GameStateManager;
public:
	GameState(GameStateProjectApp *pApp);
	virtual ~GameState() {}
	bool isActive() const { return m_active; }

protected:
	virtual void onUpdate(float deltaTime) = 0;
	virtual void onDraw() = 0;

	void enter() { m_active = true; onEnter(); }
	void exit() { m_active = false; onExit(); }

	virtual void onEnter() {}
	virtual void onExit() {}
	virtual void onPushed() {}
	virtual void onPopped() {}

	GameStateProjectApp *m_app;
private:
	bool m_active = false;
	//gameStateProjectApp* m_app;
};


class SplashState : public GameState{
public:
	SplashState(GameStateProjectApp *pApp);
	virtual ~SplashState() {}

	virtual void onEnter();
	virtual void onUpdate(float deltaTime);
	virtual void onDraw();

};

class MenuState : public GameState {
public:
	MenuState(const GameStateProjectApp *pApp);
	virtual ~MenuState() {}

	virtual void onUpdate(float deltaTime);
	virtual void onDraw();
};



class PauseState : public GameState {
public:
	PauseState(GameStateProjectApp *pApp);
	virtual ~PauseState() {}

	virtual void onUpdate(float deltaTime);
	virtual void onDraw();
};