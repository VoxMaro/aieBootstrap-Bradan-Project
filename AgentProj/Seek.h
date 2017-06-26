#pragma once
#include "IBehaviour.h"
class Seek :
	public IBehaviour
{
	Seek();
	~Seek();

	Vector2 m_targetPos;

	virtual void Update(Agent *pAgent)
	{

	}


};

