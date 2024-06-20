#pragma once

#include "../BaseEffect.h"

class EnemyAttack :public BaseEffect
{
public:

	EnemyAttack() { Init(); }
	~EnemyAttack()override {}

	void Update()override;
	void PostUpdate()override;
	void Init()override;

	void Set(Math::Vector3 _pos, Animation::Dir _dir);

private:

	Animation::Dir m_dir;

};