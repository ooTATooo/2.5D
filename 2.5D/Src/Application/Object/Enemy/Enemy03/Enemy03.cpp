#include "Enemy03.h"

#include "../../Monolith/Monolith.h"
#include "../../Player/Player.h"

void Enemy03::Update()
{
	switch (m_state)
	{
	case AnimationManager::CharaState::Idol:
		m_anime->CreateCharaAnimation("Enemy03", m_state, AnimationManager::Dir::Left, m_poly);
		break;
	case AnimationManager::CharaState::Attack:
		m_anime->CreateCharaAnimation("Enemy03", m_state, AnimationManager::Dir::Left, m_poly);
		break;
	case AnimationManager::CharaState::Run:
		m_anime->CreateCharaAnimation("Enemy03", m_state, AnimationManager::Dir::Left, m_poly);
		break;
	}

	Move();
}

void Enemy03::PostUpdate()
{
	// 球判定用の変数を作成
	KdCollider::SphereInfo sphere;
	// 球の中心点を設定
	sphere.m_sphere.Center = m_pos;
	sphere.m_sphere.Center.y += 0.5f;
	// 球の半径を設定
	sphere.m_sphere.Radius = 5.0f;
	// 当たり判定をしたいタイプを設定
	sphere.m_type = KdCollider::TypeBump;

	// デバッグ表示
	m_pDebugWire->AddDebugSphere(sphere.m_sphere.Center, sphere.m_sphere.Radius, kRedColor);

	BaseEnemy::PostUpdate();
}

void Enemy03::Init()
{
	BaseEnemy::Init();

	if (!m_poly)
	{
		m_poly = std::make_shared<KdSquarePolygon>();
		m_pos = { -5,0,21 };
		//m_pos = { 5,0,0 };
		m_anime = std::make_shared<AnimationManager>();
		m_pCollider = std::make_unique<KdCollider>();
		m_pCollider->RegisterCollisionShape("enemy03", { 0,0.5f,0 }, 0.3f, KdCollider::TypeBump);
	}
}

void Enemy03::Move()
{
	m_state = AnimationManager::CharaState::Run;

	m_moveVec = Math::Vector3::Zero;

	// 対象座標ー自分の座標
	Math::Vector3 dis;

	const std::shared_ptr<Monolith> monolith = m_monolith.lock();

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

				m_state = AnimationManager::CharaState::Attack;
			}
		}
		else
		{
			const std::shared_ptr<Player> player = m_player.lock();

			if (player)
			{
				dis = player->GetPos() - m_pos;

				if (dis.Length() < 5.0f)
				{
					m_moveVec = dis;

					if (dis.Length() < 1.0f)
					{
						m_moveVec = Math::Vector3::Zero;

						m_state = AnimationManager::CharaState::Attack;
					}
				}
			}
		}
	}

	m_moveVec.Normalize();
	m_pos += m_moveVec *= m_moveSpd;
}
