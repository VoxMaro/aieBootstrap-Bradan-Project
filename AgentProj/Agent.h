#pragma once
class Agent
{
public:
	Agent();
	~Agent();

	void Update()
	{

	}
protected:

	std::list<IBehaviour*> m_behaviours;

	Vector2 m_force;
	Vector2 m_acceleration;
	Vector2 m_velocity;
	Vector2 m_position;
};

