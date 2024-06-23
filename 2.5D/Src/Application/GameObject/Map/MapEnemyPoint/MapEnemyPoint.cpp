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
	else
	{
		m_isExpired = true;
	}

	m_pos = enemyPos;

	if (!m_frame)
	{
		m_frame = true;
	}

	if (m_pos.y > MinMap_Y + 140) { m_pos.y = MinMap_Y + 140; }
	if (m_pos.y < MinMap_Y - 140) { m_pos.y = MinMap_Y - 140; }
	if (m_pos.x > MinMap_X + 140) { m_pos.x = MinMap_X + 140; }
	if (m_pos.x < MinMap_X - 140) { m_pos.x = MinMap_X - 140; }
}

void MapEnemyPoint::PostUpdate()
{
	BaseMap::PostUpdate();
}

void MapEnemyPoint::Init()
{
	BaseMap::Init();

	m_tex = AssetManager::Instance().GetTex("MapEnemyPoint");
	m_scale = 0.1f;
}

void MapEnemyPoint::DrawSprite()
{
	if (m_frame)
	{
		m_color = { 1.0f,1.0f, 1.0f, 1.0f };
		KdShaderManager::Instance().m_spriteShader.DrawTex(m_tex, (long)m_pos.x, (long)m_pos.y, (long)(m_tex->GetWidth() * m_scale), (long)(m_tex->GetHeight() * m_scale), nullptr, &m_color);
	}
}
