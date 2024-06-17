#include "MapMonolithPoint.h"

#include "../../Stage/Monolith/Monolith.h"

void MapMonolithPoint::Update()
{
	Math::Vector3 monolithPos = Math::Vector3::Zero;
	std::shared_ptr<Monolith> monolith = m_monolith.lock();
	if (monolith)
	{
		monolithPos = Convert2D(monolith->GetPos());
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
	m_pos = {};
	m_scale = { 0.1f,0.1f,0.1f };
}

void MapMonolithPoint::DrawSprite()
{
	m_color = { 1.0f,1.0f,1.0f,1.0f };
	BaseMap::DrawSprite();
}
