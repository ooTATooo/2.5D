#include "MonolithHp.h"

#include "../../Camera/Camera.h"
#include "../../Player/Player.h"
#include "../../Stage/Monolith/Monolith.h"

void MonolithHp::Update()
{
	const std::shared_ptr<Player> player = m_player.lock();

	if (player)
	{
		if (player->GetPos().z < 0)
		{
			m_scale = 1.0f - (player->GetPos().z / -29.0f);
		}
		if (player->GetPos().z > 0)
		{
			m_scale = 1.0f + (player->GetPos().z / 29.0f);
		}
	}

	std::shared_ptr<Monolith> monolith = m_monolith.lock();
	if (monolith)
	{
		m_singleW = (float)m_Hp.tex->GetWidth() / monolith->GetMaxHp();
		m_hp = monolith->GetHp();
		if (m_hp <= 0)
		{
			m_isExpired = true;
		}
	}

	ImGuiManager::Instance().SetSize(m_scale);
}

void MonolithHp::PostUpdate()
{
	Math::Vector3 barRes = Math::Vector3::Zero;
	std::shared_ptr<Camera> camera = m_camera.lock();
	if (camera)
	{
		barRes = camera->GetConvertWorldToScreenDetail(m_pos + Math::Vector3{ -0.8f,2.5f,0 });
	}

	m_pos = barRes;

}

void MonolithHp::Init()
{
	m_backHp.tex = std::make_shared<KdTexture>();
	m_backHp.tex = AssetManager::Instance().GetTex("BarBack");

	m_Hp.tex = std::make_shared<KdTexture>();
	m_Hp.tex = AssetManager::Instance().GetTex("Bar");

	std::shared_ptr<Monolith> monolith = m_monolith.lock();
	if (monolith)
	{
		m_singleW = (float)m_Hp.tex->GetWidth() / monolith->GetMaxHp();
	}
}

void MonolithHp::DrawSprite()
{
	KdShaderManager::Instance().m_spriteShader.DrawTex(m_backHp.tex, m_pos.x, m_pos.y, m_rect.width, m_rect.height, nullptr, nullptr, { 0.0f, 0.5f });

	m_rect = { 0,0,(long)(m_singleW * m_hp),(long)m_Hp.tex->GetHeight() };
	KdShaderManager::Instance().m_spriteShader.DrawTex(m_Hp.tex, m_pos.x, m_pos.y, m_rect.width, m_rect.height, &m_rect, nullptr, { 0.0f, 0.5f });
}
