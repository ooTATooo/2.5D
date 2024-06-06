#include "Enemy02.h"

void Enemy02::Update()
{
	int run[4] = { 10,11,12,13 };
	m_poly->SetUVRect(run[(int)m_anime]);

	m_anime += 0.1f;
	if (m_anime >= 4)
	{
		m_anime = 0;
	}

	m_moveVec = Math::Vector3::Zero;

	// 対象座標ー自分の座標
	Math::Vector3 dis;

	const std::shared_ptr<KdGameObject> beacon = m_beacon.lock();

	if (beacon)
	{
		dis = beacon->GetPos() - m_pos;

		m_moveVec = dis;

		if (dis.Length() < 5.0f)
		{
			// 球判定・・・ベクトルの長さで判定
			if (dis.Length() < 3.0f)
			{
				// ビーコン前で止まる
				m_moveVec = Math::Vector3::Zero;
			}
		}
		else
		{
			const std::shared_ptr<KdGameObject> player = m_player.lock();

			if (player)
			{
				dis = player->GetPos() - m_pos;

				if (dis.Length() < 3.0f)
				{
					m_moveVec = Math::Vector3::Zero;
				}
			}
		}
	}
	m_moveVec.Normalize();
	m_pos += m_moveVec *= m_moveSpd;
}

void Enemy02::PostUpdate()
{
	BaseEnemy::PostUpdate();
}

void Enemy02::Init()
{
	BaseEnemy::Init();

	if (!m_poly)
	{
		m_poly = std::make_shared<KdSquarePolygon>();
		m_poly->SetMaterial("Asset/Textures/Enemy02/witch01.png");
		m_poly->SetSplit(14, 1);
		m_poly->SetPivot(KdSquarePolygon::PivotType::Center_Bottom);
		m_poly->SetScale(2);
		m_pos = { 5,0,21 };
		//m_pos = { 4,0,0 };
		m_pCollider = std::make_unique<KdCollider>();
		m_pCollider->RegisterCollisionShape("enemy02", { 0,0.5f,0 }, 0.3f, KdCollider::TypeBump);
	}
}