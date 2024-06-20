#pragma once

class BaseBullet :public KdGameObject
{
public:

	BaseBullet() {}
	~BaseBullet()override {}

	void Update()override {};
	void PostUpdate()override;
	void Init()override;
	void DrawLit()override;
	void DrawBright()override;
	void OnHit()override {}

	void shot(Math::Vector3 _startPos, Math::Vector3 _targetPos);

protected:

	std::shared_ptr<KdSquarePolygon> m_poly = nullptr;

	float m_moveSpd = 0;
	Math::Vector3 m_moveVec = Math::Vector3::Zero;

	Math::Vector3 m_pos = Math::Vector3::Zero;
	Math::Vector3 m_scale = Math::Vector3::Zero;

	bool m_alive = false;

	std::shared_ptr<Animation> m_anime = nullptr;

};