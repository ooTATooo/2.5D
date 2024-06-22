#pragma once

#include "../BaseEffect.h"

class EnemyBulletHit :public BaseEffect
{
public:

	EnemyBulletHit() { Init(); }
	~EnemyBulletHit()override {}

	void Update()override;
	void PostUpdate()override;
	void Init()override;

	void Set(Math::Vector3 _pos);

private:
};