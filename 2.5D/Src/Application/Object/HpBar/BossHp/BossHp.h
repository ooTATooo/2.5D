#pragma once

#include "../BaseHpBar.h"

class BossHp :public BaseHpBar
{
public:

	BossHp() { Init(); }
	~BossHp()override {}

	void Update()override;
	void PostUpdate()override;
	void Init()override;
	void DrawSprite()override;

private:
};