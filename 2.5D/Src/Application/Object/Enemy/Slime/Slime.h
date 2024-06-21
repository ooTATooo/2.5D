#pragma once

#include "../BaseEnemy.h"

class Slime :public BaseEnemy
{
public:

	Slime() { Init(); }
	~Slime()override {}

	void Update()override;
	void Init()override;

private:

	void Move();
};