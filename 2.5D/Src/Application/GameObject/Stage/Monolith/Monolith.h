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
	void OnHit()override;

	Math::Vector3 GetPos()const { return m_pos; }
	bool GetAlive()const { return m_alive; }
	int GetHp()const { return m_hp; }
	int GetMaxHp()const { return m_maxHp; }

	void Expired() { m_isExpired = true; }

private:

	std::shared_ptr<KdModelData> m_model01 = nullptr;
	std::shared_ptr<KdModelData> m_model02 = nullptr;

	Math::Vector3 m_pos = Math::Vector3::Zero;
	float m_ang = 0;
	float m_speed;
	int m_maxHp;
	int m_hp;
	float m_hitWait = 0;

	float alpha;
	Math::Color m_color01;
	Math::Color m_color02;

	bool m_alive = true;

	bool m_dissolveFlg = false;
	float m_dissolve = 0;

	bool m_soundFlg = false;
};