#include "Knight.h"

#include "../../Stage/Monolith/Monolith.h"
#include "../../Player/Player.h"

void Knight::Update()
{
	switch (m_state)
	{
	case Animation::State::Attack:
		m_anime->CreateAnimation("KnightAttack", m_poly, true);
		break;
	case Animation::State::Run:
		m_anime->CreateAnimation("KnightRun", m_poly, true);
		break;
	case Animation::State::Hit:
		m_anime->CreateAnimation("KnightHit", m_poly, false);
		break;
	case Animation::State::Die:
		m_anime->CreateAnimation("KnightDie", m_poly, true);
		break;
	}

	if (m_state != Animation::State::Die)
	{
		Move();
	}

	m_hitWait--;
	if (m_hitWait <= 0) { m_hitWait = 0; }
}

void Knight::Init()
{
	BaseEnemy::Init();

	m_poly = std::make_shared<KdSquarePolygon>();
	m_maxHp = 5;
	m_hp = m_maxHp;

	m_anime = std::make_shared<Animation>();

	m_pCollider = std::make_unique<KdCollider>();
	m_pCollider->RegisterCollisionShape("enemy03", { 0,0.5f,0 }, 0.3f, KdCollider::TypeBump | KdCollider::TypeDamage);
}

void Knight::Move()
{
	if (!m_anime->GetAnimationFlg())
	{
		m_state = Animation::State::Run;
	}

	m_moveVec = Math::Vector3::Zero;

	// 対象座標ー自分の座標
	Math::Vector3 dis;

	const std::shared_ptr<const KdGameObject> monolith = m_monolith.lock();

	if (monolith)
	{
		dis = monolith->GetPos() - m_pos;

		m_moveVec = dis;

		if (dis.Length() < 5.0f)
		{
			// 球判定・・・ベクトルの長さで判定
			if (dis.Length() < 2.0f)
			{
				// ビーコン前で止まる
				m_moveVec = Math::Vector3::Zero;

				if (!m_anime->GetAnimationFlg())
				{
					m_state = Animation::State::Attack;
				}
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

					if (dis.Length() < 1.0f)
					{
						m_moveVec = Math::Vector3::Zero;

						if (!m_anime->GetAnimationFlg())
						{
							m_state = Animation::State::Attack;
						}
					}
				}
			}
		}
	}

	m_moveVec.Normalize();
	m_pos += m_moveVec *= m_moveSpd;
}
