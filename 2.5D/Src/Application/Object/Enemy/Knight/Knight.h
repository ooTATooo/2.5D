#pragma once

#include "../BaseEnemy.h"

class Knight :public BaseEnemy
{
public:

	Knight() { Init(); }
	~Knight()override {}

	void Update()override;
	void Init()override;

private:

	void Move();

};