#pragma once

#include "../BaseHpBar.h"
class Player;

class MonumentHp :public BaseHpBar
{
public:

	MonumentHp() { Init(); }
	~MonumentHp()override {}

	void Update()override;
	void PostUpdate()override;
	void Init()override;
	void DrawSprite()override;
private:
};