#pragma once

#include "../BaseUI.h"

class GameOverBack :public BaseUI
{
public:

	GameOverBack() { Init(); }
	~GameOverBack() {}

	void Update()override;
	void Init()override;
	void DrawSprite()override;

private:

	float m_alpha = 0.0f;
	float m_alphaAdd = 0.01f;

	Math::Color m_color;
};