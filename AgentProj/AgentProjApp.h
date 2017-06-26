#pragma once

#include "Application.h"
#include "Renderer2D.h"

class AgentProjApp : public aie::Application {
public:

	AgentProjApp();
	virtual ~AgentProjApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;
};