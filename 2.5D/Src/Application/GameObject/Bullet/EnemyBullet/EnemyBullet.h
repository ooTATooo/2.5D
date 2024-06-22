#pragma once

#include "../BaseBullet.h"

class EnemyBullet :public BaseBullet
{
public:

	EnemyBullet() { Init(); }
	~EnemyBullet()override {}

	void Update()override;
	void PostUpdate()override;
	void Init()override;
	void OnHit()override;

private:
};