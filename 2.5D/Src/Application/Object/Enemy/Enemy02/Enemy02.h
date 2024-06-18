#pragma once

#include "../BaseEnemy.h"

class Enemy02 :public BaseEnemy
{
public:

	Enemy02() { Init(); }
	~Enemy02()override {}

	void Update()override;
	void PostUpdate()override;
	void Init()override;
	void OnHit()override;

private:

	void Move();

	float shotWait = 30;

};