#include "Boss.h"

void Boss::Update()
{
	switch (m_state)
	{
	case AnimationManager::State::Idol:
		m_anime->CreateAnime("Boss", AnimationManager::State::Idol, AnimationManager::Dir::Left, m_poly);
		break;
	case AnimationManager::State::Attack:
		m_anime->CreateAnime("Boss", AnimationManager::State::Attack, AnimationManager::Dir::Left, m_poly);
		break;
	case AnimationManager::State::Run:
		m_anime->CreateAnime("Boss", AnimationManager::State::Run, AnimationManager::Dir::Left, m_poly);
		break;
	}

	m_state = AnimationManager::State::Run;
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
		m_anime = std::make_shared<AnimationManager>();
		m_pCollider = std::make_unique<KdCollider>();
		m_pCollider->RegisterCollisionShape("Boss", { 0,0.5f,0 }, 0.3f, KdCollider::TypeBump);
	}
}
