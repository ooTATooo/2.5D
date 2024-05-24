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

	std::shared_ptr<KdModelData> m_model;
};