#include "Enemy01.h"

void Enemy01::Update()
{
	AnimationManager::Instance().CreateAnime(AnimationManager::Dir::Left, AnimationManager::State::Run, m_poly);

	Move();
}

void Enemy01::PostUpdate()
{


	BaseEnemy::PostUpdate();
}

void Enemy01::Init()
{
	BaseEnemy::Init();

	if (!m_poly)
	{
		m_poly = std::make_shared<KdSquarePolygon>();
		m_pos = { -5,0,-21 };
		m_pCollider = std::make_unique<KdCollider>();
		m_pCollider->RegisterCollisionShape("enemy01", { 0,0.5f,0 }, 0.3f, KdCollider::TypeBump);
	}
}

void Enemy01::Move()
{
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

				if (dis.Length() < 5.0f)
				{
					m_moveVec = dis;
				}
			}
		}
	}

	m_moveVec.Normalize();
	m_pos += m_moveVec *= m_moveSpd;
}
