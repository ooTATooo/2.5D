#pragma once

class WallFrame :public KdGameObject
{
public:

	WallFrame() { Init(); }
	~WallFrame()override {}

	void PreUpdate()override;
	void Init()override;
	void GenerateDepthMapFromLight()override;
	void DrawLit()override;
	void Hit()override;

private:

	std::shared_ptr<KdModelData> m_model01;
	std::shared_ptr<KdModelData> m_model02;
	std::shared_ptr<KdModelData> m_modelHit;

	float m_alpha;

	Math::Color m_color;

};