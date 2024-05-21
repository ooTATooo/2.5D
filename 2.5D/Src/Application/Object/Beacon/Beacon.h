#pragma once

class Beacon :public KdGameObject
{
public:

	Beacon() {}
	~Beacon()override {}

	void Init()override;
	void GenerateDepthMapFromLight()override;
	void DrawLit()override;

private:

	KdModelData m_model;
};