#include "GameStateManager.h"

#include "GameState.h"

#include <vector>


void GameStateManager::registerState(int id, GameState * state)
{
	m_registeredStates[id] = state;
}

void GameStateManager::pushState(int id)
{
	m_pushedStates.push_back(m_registeredStates[id]);
}

void GameStateManager::popState()
{
	m_popState = true;
}

void GameStateManager::update(float deltaTime)
{
	while (m_popState) {
		m_popState = false;

		m_stateStack.back()->exit();
		auto temp = m_stateStack.back;
		m_stateStack.pop_back();
		temp->onPopped();


		if (m_stateStack.empty() == false)
			m_stateStack.back()->enter();
	}
	for (auto pushedState : m_pushedStates) {
		if (m_stateStack.empty() == false)
			m_stateStack.back()->exit();

		pushedState->onPushed();
		m_stateStack.push_back(pushedState);
		m_stateStack.back()->enter();
	}
	m_pushedStates.clear();

	for (auto state : m_stateStack)
		state->onUpdate(deltaTime);
}
