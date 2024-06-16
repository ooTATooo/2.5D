#pragma once

class Pillar :public KdGameObject
{
public:

	Pillar() { Init(); }
	~Pillar()override {}

	void PreUpdate()override;
	void Init()override;
	void GenerateDepthMapFromLight()override;
	void DrawLit()override;
	void Hit()override;

	void SetPos(const Math::Vector3 _pos) { m_mWorld.Translation(_pos); }

private:

	std::shared_ptr<KdModelData> m_model;

	float m_alpha;

	Math::Color m_color;
};