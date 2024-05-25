#pragma once

class Beacon :public KdGameObject
{
public:

	Beacon() { Init(); }
	~Beacon()override {};

	void Init()override;
	void GenerateDepthMapFromLight()override;
	void DrawLit()override;

private:

	std::shared_ptr<KdModelData> m_model;

	Math::Color color = { 1,1,1,0.8f };

};