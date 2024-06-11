#pragma once

#include "../BaseEnemy.h"

class Enemy03 :public BaseEnemy
{
public:

	Enemy03() { Init(); }
	~Enemy03()override {}

	void Update()override;
	void PostUpdate()override;
	void Init()override;

private:

	void Move();

};