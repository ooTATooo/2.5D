#pragma once

class Pillar :public KdGameObject
{
public:

	Pillar() { Init(); }
	~Pillar()override {}

	void Update()override;
	void Init()override;
	void GenerateDepthMapFromLight()override;
	void DrawLit()override;

private:

	std::shared_ptr<KdModelData> m_model;

	Math::Color m_color = { 1.0f,1.0f,1.0f,1.0f };
};