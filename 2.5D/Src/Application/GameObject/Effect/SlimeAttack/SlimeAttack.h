#pragma once

#include "../BaseEffect.h"

class SlimeAttack :public BaseEffect
{
public:

	SlimeAttack() { Init(); }
	~SlimeAttack()override {}

	void Update()override;
	void PostUpdate()override;
	void Init()override;
	void DrawUnLit()override {}
	void DrawBright()override {}

	void Set(Math::Vector3 _startPos, Math::Vector3 _targetPos);

private:
};