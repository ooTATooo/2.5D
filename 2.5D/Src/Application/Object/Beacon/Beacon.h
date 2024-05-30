#pragma once

class Beacon :public KdGameObject
{
public:

	Beacon() { Init(); }
	~Beacon()override {};

	void Init()override;
	void GenerateDepthMapFromLight()override;
	void DrawLit()override;
	void DrawBright()override;

	//Math::Vector3 GetPos() const override{ return m_mWorld.Translation(); }
private:

	std::shared_ptr<KdModelData> m_model;

	Math::Color color = { 1,1,1,0.35f };

};