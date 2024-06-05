#pragma once

#include "../BaseEnemy.h"

class Enemy01 :public BaseEnemy
{
public:

	Enemy01() { Init(); }
	~Enemy01()override {}

	void Update()override;
	void PostUpdate()override;
	void Init()override;

private:


};