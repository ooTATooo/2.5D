#pragma once

#include "../TitleLBaseUI.h"

class TitleStart :public TitleBaseUI
{
public:

	TitleStart() { Init(); }
	~TitleStart()override {}

	void Update()override;
	void Init()override;
	void DrawSprite()override;

private:

	float m_alpha = 1.0f;
	float m_alphaAdd = 0.01f;
	Math::Color m_color;

};