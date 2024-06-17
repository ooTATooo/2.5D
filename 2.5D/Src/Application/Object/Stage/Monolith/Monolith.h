#pragma once

#include "../BaseStage.h"

class Monolith :public BaseStage
{
public:

	Monolith() { Init(); }
	~Monolith()override {};

	void Update()override;
	void PostUpdate()override;
	void Init()override;
	void GenerateDepthMapFromLight()override;
	void DrawLit()override;
	void DrawBright()override;

	const Math::Vector3 GetPos()const { return m_pos; }

private:

	std::shared_ptr<KdModelData> m_model01 = nullptr;
	std::shared_ptr<KdModelData> m_model02 = nullptr;

	Math::Vector3 m_pos;
	float m_ang;
	float m_speed;
	float alpha;

	Math::Color m_color01;
	Math::Color m_color02;

	bool flg = false;

};