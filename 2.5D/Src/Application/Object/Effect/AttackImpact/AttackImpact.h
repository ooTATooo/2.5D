#pragma once

#include "../BaseEffect.h"

class AttackImpact :public BaseEffect
{
public:

	AttackImpact() { Init(); }
	~AttackImpact()override {}

	void Update()override;
	void PostUpdate()override;
	void Init()override;

	void Set(Math::Vector3 _pos);

private:
};