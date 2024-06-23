#pragma once

#include "../BaseUI.h"

class GameClear :public BaseUI
{
public:

	GameClear() { Init(); }
	~GameClear() {}

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