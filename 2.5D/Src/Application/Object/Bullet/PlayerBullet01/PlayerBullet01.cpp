#include "PlayerBullet01.h"

void PlayerBullet01::Update()
{
	//switch (m_state)
	//{
	//case Animation::BulletState::Idol:
	//	m_anime->CreateBulletAnimation("PlayerBullet01", m_state, Animation::Dir::Left, m_poly);
	//	break;
	//case Animation::BulletState::Shot:
	//	break;
	//case Animation::BulletState::Hit:
	//	break;
	//default:
	//	break;
	//}

	//m_state = Animation::BulletState::Idol;

	//m_moveVec.Normalize();
	//m_pos += m_moveVec *= m_moveSpd;
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
		m_anime = std::make_shared<Animation>();
		m_pCollider = std::make_unique<KdCollider>();
		//m_pCollider->RegisterCollisionShape("enemy01", { 0,0.5f,0 }, 0.3f, KdCollider::TypeBump);
	}
}
