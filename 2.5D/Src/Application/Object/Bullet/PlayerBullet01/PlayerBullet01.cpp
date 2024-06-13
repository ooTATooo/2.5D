﻿#include "PlayerBullet01.h"

void PlayerBullet01::Update()
{
	switch (m_state)
	{
	case AnimationManager::BulletState::Idol:
		m_anime->CreateBulletAnimation("PlayerBullet01", m_state, AnimationManager::Dir::Left, m_poly);
		break;
	case AnimationManager::BulletState::Shot:
		break;
	case AnimationManager::BulletState::Hit:
		break;
	default:
		break;
	}

	m_state = AnimationManager::BulletState::Idol;

	m_moveVec.Normalize();
	m_pos += m_moveVec *= m_moveSpd;
}

void PlayerBullet01::PostUpdate()
{
	BaseBullet::PostUpdate();
}

void PlayerBullet01::Init()
{
	BaseBullet::Init();

	if (!m_poly)
	{
		m_poly = std::make_shared<KdSquarePolygon>();
		m_anime = std::make_shared<AnimationManager>();
		m_pCollider = std::make_unique<KdCollider>();
		//m_pCollider->RegisterCollisionShape("enemy01", { 0,0.5f,0 }, 0.3f, KdCollider::TypeBump);
	}
}
