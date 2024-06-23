#pragma once

#include "../BaseUI.h"

class GameOver :public BaseUI
{
public:

	GameOver() { Init(); }
	~GameOver() {}

	void Update()override;
	void Init()override;
	void DrawSprite()override;

private:

	float m_alpha;
	float m_alphaAdd;

	int m_frame;
	bool m_frameFlg;
	bool m_changeFlg;

	Math::Color m_color;
};