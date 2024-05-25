#pragma once

class Pillar :public KdGameObject
{
public:

	Pillar() {}
	~Pillar()override {}

	void Update()override;
	void Init()override;
	void GenerateDepthMapFromLight()override;
	void DrawLit()override;

private:

	std::shared_ptr<KdModelData> m_model;

	static const int width = 4;
	static const int height = 4;

	struct Data
	{
		Math::Vector3 pos;
		Math::Color color;
	};

	Data m_pillar[width][height];
};