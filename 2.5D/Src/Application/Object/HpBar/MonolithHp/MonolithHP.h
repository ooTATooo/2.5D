#pragma once

#include "../BaseHpBar.h"

class MonolithHp :public BaseHpBar
{
public:

	MonolithHp() { Init(); }
	~MonolithHp()override {}

	void Update()override;
	void PostUpdate()override;
	void Init()override;
	void DrawSprite()override;
private:

	int m_hp;
	int m_maxHp;
	float m_singleW;
};