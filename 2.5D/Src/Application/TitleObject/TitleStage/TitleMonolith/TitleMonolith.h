#pragma once

#include "../TitleBaseStage.h"

class TitleMonolith :public TitleBaseStage
{
public:

	TitleMonolith() { Init(); }
	~TitleMonolith()override {};

	void Update()override;
	void PostUpdate()override;
	void Init()override;
	void GenerateDepthMapFromLight()override;
	void DrawLit()override;
	void DrawBright()override;

private:

	std::shared_ptr<KdModelData> m_model01 = nullptr;
	std::shared_ptr<KdModelData> m_model02 = nullptr;

	float m_ang = 0;
	float m_speed;

	float m_alpha;
	Math::Color m_color01;
	Math::Color m_color02;

};