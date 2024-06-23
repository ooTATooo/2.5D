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

		KdAudioManager::Instance().Play("Asset/Sounds/EnemyBullet.wav", false, 0.1f);
	}
}

void EnemyBullet::OnHit()
{
	std::shared_ptr<EnemyBulletHit> bulletHit = std::make_shared<EnemyBulletHit>();
	bulletHit->Set(m_pos);
	SceneManager::Instance().AddObject(bulletHit);

	m_isExpired = true;
}
