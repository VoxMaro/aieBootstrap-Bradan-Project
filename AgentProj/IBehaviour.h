#pragma once
class IBehaviour
{
	IBehaviour();
	~IBehaviour();

	virtual void Update(Agent *pAgent) = 0;
};

