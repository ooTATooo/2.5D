#pragma once

#include "../TitleBaseStage.h"

class TitleWallFrame :public TitleBaseStage
{
public:

	TitleWallFrame() { Init(); }
	~TitleWallFrame()override {}

	void Init()override;
	void GenerateDepthMapFromLight()override;
	void DrawLit()override;

private:

	std::shared_ptr<KdModelData> m_model;

};