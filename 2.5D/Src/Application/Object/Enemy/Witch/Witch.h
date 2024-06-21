#pragma once

#include "../BaseEnemy.h"

class Witch :public BaseEnemy
{
public:

	Witch() { Init(); }
	~Witch()override {}

	void Update()override;
	void Init()override;

private:

	void Move();

	float shotWait = 30;

};