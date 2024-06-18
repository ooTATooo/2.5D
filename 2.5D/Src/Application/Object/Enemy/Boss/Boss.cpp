#include "Boss.h"

void Boss::Update()
{
	switch (m_state)
	{
	case Animation::State::Idol:
		m_anime->CreateAnimation("BossIdol", m_poly, true);
		break;
	case Animation::State::Attack:
		m_anime->CreateAnimation("BossAttack", m_poly, true);
		break;
	case Animation::State::Run:
		m_anime->CreateAnimation("BossRun", m_poly, true);
		break;
	}

	m_state = Animation::State::Run;
}

void Boss::PostUpdate()
{
	BaseEnemy::PostUpdate();
}

void Boss::Init()
{
	BaseEnemy::Init();

	if (!m_poly)
	{
		m_poly = std::make_shared<KdSquarePolygon>();
		m_pos = { 0,0,5 };
		m_anime = std::make_shared<Animation>();
		m_pCollider = std::make_unique<KdCollider>();
		m_pCollider->RegisterCollisionShape("Boss", { 0,0.5f,0 }, 0.3f, KdCollider::TypeBump);
	}
}
