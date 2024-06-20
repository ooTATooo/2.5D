#include "EnemyBulletHit.h"

void EnemyBulletHit::Update()
{
	m_anime->CreateAnimation("EnemyBulletHit", m_poly, false);

	if (!m_anime->GetAnimationFlg())
	{
		m_isExpired = true;
	}
}

void EnemyBulletHit::PostUpdate()
{
	BaseEffect::PostUpdate();
}

void EnemyBulletHit::Init()
{
	BaseEffect::Init();

	if (!m_poly)
	{
		m_poly = std::make_shared<KdSquarePolygon>();
		m_anime = std::make_shared<Animation>();
		m_scale = { 2,2,2 };

		m_pDebugWire = std::make_unique<KdDebugWireFrame>();
	}
}

void EnemyBulletHit::Set(Math::Vector3 _pos)
{
	m_pos = _pos;
}
