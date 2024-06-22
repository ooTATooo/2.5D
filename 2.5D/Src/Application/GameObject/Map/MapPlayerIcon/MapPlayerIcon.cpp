#include "MapPlayerIcon.h"

#include "../../Player/Player.h"

void MapPlayerIcon::Update()
{
	Math::Vector3 playerPos = Math::Vector3::Zero;
	std::shared_ptr<Player> player = m_player.lock();
	if (player)
	{
		playerPos = Convert2D(player->GetPos());

		if (m_dir != player->GetDir())
		{
			m_scale.x *= -1;
			m_dir = player->GetDir();
		}
	}

	m_pos = playerPos;
	ImGuiManager::Instance().SetPlayer2DPos(m_pos);
}

void MapPlayerIcon::PostUpdate()
{
	BaseMap::PostUpdate();
}

void MapPlayerIcon::Init()
{
	BaseMap::Init();
	m_tex = AssetManager::Instance().GetTex("MapPlayerIcon");
	m_pos = {};
	m_scale = { -0.2f,0.2f };
	m_dir = Animation::Dir::Left;
}

void MapPlayerIcon::DrawSprite()
{
	m_color = { 1.0f,1.0f, 1.0f, 1.0f };
	KdShaderManager::Instance().m_spriteShader.DrawTex(m_tex, (int)m_pos.x, (int)m_pos.y, (int)(m_tex->GetWidth() * m_scale.x), (int)(m_tex->GetHeight() * m_scale.y), nullptr, &m_color);}
