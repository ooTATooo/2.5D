#pragma once

#include "../TitleBaseStage.h"

class TitlePillar :public TitleBaseStage
{
public:

	TitlePillar() { Init(); }
	~TitlePillar()override {}

	void Init()override;
	void GenerateDepthMapFromLight()override;
	void DrawLit()override;

private:

	std::shared_ptr<KdModelData> m_model;

};