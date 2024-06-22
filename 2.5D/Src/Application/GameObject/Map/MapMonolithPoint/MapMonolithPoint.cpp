#include "MapMonolithPoint.h"

#include "../../Stage/Monolith/Monolith.h"

void MapMonolithPoint::Update()
{
	Math::Vector3 monolithPos = Math::Vector3::Zero;
	std::shared_ptr<Monolith> monolith = m_monolith.lock();
	if (monolith)
	{
		monolithPos = Convert2D(monolith->GetPos());
		if (monolith->GetHp() <= 0)
		{
			m_isExpired = true;
		}
	}

	m_pos = monolithPos;
}

void MapMonolithPoint::PostUpdate()
{
	BaseMap::PostUpdate();
}

void MapMonolithPoint::Init()
{
	BaseMap::Init();

	m_tex = AssetManager::Instance().GetTex("MapMonolithPoint");
	m_scale = 0.1f;
}

void MapMonolithPoint::DrawSprite()
{
	m_color = { 1.0f,1.0f, 1.0f, 1.0f };
	KdShaderManager::Instance().m_spriteShader.DrawTex(m_tex, (long)m_pos.x, (long)m_pos.y, (long)(m_tex->GetWidth() * m_scale), (long)(m_tex->GetHeight() * m_scale), nullptr, &m_color);
}
