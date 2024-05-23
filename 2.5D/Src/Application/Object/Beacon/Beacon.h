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

};