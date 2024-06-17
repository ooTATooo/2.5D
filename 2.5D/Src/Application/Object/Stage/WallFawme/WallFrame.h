#pragma once

#include "../BaseStage.h"

class WallFrame :public BaseStage
{
public:

	WallFrame() { Init(); }
	~WallFrame()override {}

	void PreUpdate()override;
	void Init()override;
	void GenerateDepthMapFromLight()override;
	void DrawLit()override;
	void OnHit()override;

private:

	std::shared_ptr<KdModelData> m_model01;
	std::shared_ptr<KdModelData> m_model02;
	std::shared_ptr<KdModelData> m_modelHit;

};