#pragma once

#include "../BaseStage.h"

class Pillar :public BaseStage
{
public:

	Pillar() { Init(); }
	~Pillar()override {}

	void PreUpdate()override;
	void Init()override;
	void GenerateDepthMapFromLight()override;
	void DrawLit()override;
	void OnHit()override;

	void SetPos(const Math::Vector3 _pos) { m_mWorld.Translation(_pos); }

private:

	std::shared_ptr<KdModelData> m_model;
};