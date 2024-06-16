#include "MapEnemyPoint.h"

#include "../../Enemy/BaseEnemy.h"

void MapEnemyPoint::Update()
{
	Math::Vector3 enemyPos = Math::Vector3::Zero;
	std::shared_ptr<BaseEnemy> enemy = m_enemy.lock();
	if (enemy)
	{
		enemyPos = Convert2D(enemy->GetPos());
	}

	m_pos = enemyPos;
}

void MapEnemyPoint::PostUpdate()
{
	BaseMap::PostUpdate();
}

void MapEnemyPoint::Init()
{
	BaseMap::Init();
	m_tex = AssetManager::Instance().GetTex("MapEnemyPoint");
	m_pos = {};
	m_scale = { 0.1f,0.1f,0.1f };
}

void MapEnemyPoint::DrawSprite()
{
	m_color = { 1.0f,1.0f,1.0f,1.0f };
	BaseMap::DrawSprite();
}
