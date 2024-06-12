#include "Boss.h"

void Boss::Update()
{
	switch (m_state)
	{
	case AnimationManager::CharaState::Idol:
		m_anime->CreateCharaAnimation("Boss", m_state, AnimationManager::Dir::Left, m_poly);
		break;
	case AnimationManager::CharaState::Attack:
		m_anime->CreateCharaAnimation("Boss", m_state, AnimationManager::Dir::Left, m_poly);
		break;
	case AnimationManager::CharaState::Run:
		m_anime->CreateCharaAnimation("Boss", m_state, AnimationManager::Dir::Left, m_poly);
		break;
	}

	m_state = AnimationManager::CharaState::Run;
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
