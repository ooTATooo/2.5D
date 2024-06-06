#include "PlayerBullet01.h"

void PlayerBullet01::Update()
{
	//int run[5] = { 0,1,2,3,4 };
	//m_poly->SetUVRect(run[(int)m_anime]);

	//m_anime += 0.1f;
	//if (m_anime >= 5)
	//{
	//	m_anime = 0;
	//}
	m_poly->SetUVRect(0);

	m_moveVec = m_mousePos - m_playerPos;

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
		m_poly->SetMaterial("Asset/Textures/PlayerBullet01/bullet.png");
		m_poly->SetSplit(4, 1);
		m_poly->SetPivot(KdSquarePolygon::PivotType::Center_Bottom);
		m_pCollider = std::make_unique<KdCollider>();
		//m_pCollider->RegisterCollisionShape("enemy01", { 0,0.5f,0 }, 0.3f, KdCollider::TypeBump);
	}
}

void PlayerBullet01::shot(Math::Vector3 _playerPos, Math::Vector3 _mousePos)
{
	m_alive = true;
	m_playerPos = _playerPos;
	m_mousePos = _mousePos;
}

