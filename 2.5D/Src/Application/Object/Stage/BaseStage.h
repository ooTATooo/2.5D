#pragma once

class BaseStage :public KdGameObject
{
public:

	BaseStage() {}
	~BaseStage()override {}

	void PreUpdate()override {}
	void Init()override;
	void GenerateDepthMapFromLight()override {}
	void DrawLit()override {}
	void DrawUnLit()override {}
	void DrawBright()override {}

	void OnHit()override {}

protected:

	float m_alpha;
	float m_alphaSpd;
	bool m_alphaFlg;

	Math::Color m_color;

};