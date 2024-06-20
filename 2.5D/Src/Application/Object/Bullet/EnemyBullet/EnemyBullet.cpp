#include "EnemyBullet.h"

#include "../../Effect/EnemyBulletHit/EnemyBulletHit.h"

void EnemyBullet::Update()
{
	m_anime->CreateAnimation("EnemyBulletIdol", m_poly, true);

	m_moveVec.Normalize();
	m_pos += m_moveVec *= m_moveSpd;
}

void EnemyBullet::PostUpdate()
{
	BaseBullet::PostUpdate();
}

void EnemyBullet::Init()
{
	BaseBullet::Init();

	if (!m_poly)
	{
		m_poly = std::make_shared<KdSquarePolygon>();
		m_anime = std::make_shared<Animation>();
		m_pCollider = std::make_unique<KdCollider>();
		m_pCollider->RegisterCollisionShape("EnemyBullet", { 0,0.5f,0 }, 0.3f, KdCollider::TypeBump);
	}
}

void EnemyBullet::OnHit()
{
	std::shared_ptr<EnemyBulletHit> bulletHit = std::make_shared<EnemyBulletHit>();
	bulletHit->Set(m_pos);
	SceneManager::Instance().AddObject(bulletHit);

	m_isExpired = true;
}
