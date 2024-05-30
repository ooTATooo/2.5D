#pragma once

class WallFrame :public KdGameObject
{
public:

	WallFrame() { Init(); }
	~WallFrame()override {}

	void Init()override;
	void GenerateDepthMapFromLight()override;
	void DrawLit()override;

private:

	std::shared_ptr<KdModelData> m_model01;
	std::shared_ptr<KdModelData> m_model02;
	std::shared_ptr<KdModelData> m_modelHit;

	Math::Color color = { 1,1,1,1.0f };

};