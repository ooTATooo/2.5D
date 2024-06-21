#include "Witch.h"

#include "../../Bullet/EnemyBullet/EnemyBullet.h"
#include "../../Stage/Monolith/Monolith.h"
#include "../../Player/Player.h"

void Witch::Update()
{
	switch (m_state)
	{
	case Animation::State::Attack:
		m_anime->CreateAnimation("WitchAttack", m_poly, true);
		break;
	case Animation::State::Run:
		m_anime->CreateAnimation("WitchRun", m_poly, true);
		break;
	case Animation::State::Hit:
		m_anime->CreateAnimation("WitchHit", m_poly, false);
		break;
	case Animation::State::Die:
		m_anime->CreateAnimation("WitchDie", m_poly, true);
		break;
	}

	if (m_state != Animation::State::Die)
	{
		Move();
	}

	m_hitWait--;
	if (m_hitWait <= 0) { m_hitWait = 0; }
}

void Witch::Init()
{
	BaseEnemy::Init();

	m_poly = std::make_shared<KdSquarePolygon>();
	m_maxHp = 3;
	m_hp = m_maxHp;

	m_anime = std::make_shared<Animation>();

	m_pCollider = std::make_unique<KdCollider>();
	m_pCollider->RegisterCollisionShape("enemy02", { 0,0.5f,0 }, 0.3f, KdCollider::TypeBump | KdCollider::TypeDamage);
}

void Witch::Move()
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

					if (shotWait <= 0)
					{
						std::shared_ptr<EnemyBullet> bullet = std::make_shared<EnemyBullet>();
						bullet->shot(m_pos, monolith->GetPos());
						SceneManager::Instance().AddObject(bullet);
						shotWait = 120;
					}
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
					m_moveVec = Math::Vector3::Zero;

					if (!m_anime->GetAnimationFlg())
					{
						m_state = Animation::State::Attack;

						if (shotWait <= 0)
						{
							std::shared_ptr<EnemyBullet> bullet = std::make_shared<EnemyBullet>();
							bullet->shot(m_pos, player->GetPos());
							SceneManager::Instance().AddObject(bullet);
							shotWait = 120;
						}
					}
				}
			}
		}
	}

	shotWait--;
	if (shotWait == 0)
	{
		shotWait = 0;
	}

	m_moveVec.Normalize();
	m_pos += m_moveVec *= m_moveSpd;
}
