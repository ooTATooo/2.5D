#include "AttackImpact.h"

void AttackImpact::Update()
{
	m_anime->CreateAnimation("PlayerAtkImpact", m_poly, false);

	if (!m_anime->GetAnimationFlg())
	{
		m_isExpired = true;
	}
}

void AttackImpact::PostUpdate()
{
	BaseEffect::PostUpdate();
}

void AttackImpact::Init()
{
	BaseEffect::Init();

	if (!m_poly)
	{
		m_poly = std::make_shared<KdSquarePolygon>();
		m_anime = std::make_shared<Animation>();
		m_scale = { 2,2,2 };
	}
}

void AttackImpact::Set(Math::Vector3 _pos)
{
	m_pos = _pos;
}
