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

	const std::shared_ptr<Monolith> monolith = m_monolith.lock();
	if (monolith)
	{
		m_singleW = (float)m_tex02->GetWidth() / monolith->GetMaxHp();
		m_hp = monolith->GetHp();
		if (m_hp <= 0)
		{
			m_isExpired = true;
		}
		m_pos = monolith->GetPos();
	}

	Math::Vector3 barRes = Math::Vector3::Zero;
	std::shared_ptr<Camera> camera = m_camera.lock();
	if (camera)
	{
		barRes = camera->GetConvertWorldToScreenDetail(m_pos + Math::Vector3{ -0.8f,2.5f,0 });
	}

	m_pos = barRes;

	ImGuiManager::Instance().SetSize(m_scale);
}

void MonolithHp::PostUpdate()
{
}

void MonolithHp::Init()
{
	m_tex01 = std::make_shared<KdTexture>();
	m_tex01 = AssetManager::Instance().GetTex("BarBack");

	m_tex02 = std::make_shared<KdTexture>();
	m_tex02 = AssetManager::Instance().GetTex("Bar");

	std::shared_ptr<Monolith> monolith = m_monolith.lock();
	if (monolith)
	{
		m_singleW = (float)m_tex02->GetWidth() / monolith->GetMaxHp();
	}
}

void MonolithHp::DrawSprite()
{
	m_rect = { 0,0,(long)m_tex01->GetWidth(),(long)m_tex01->GetHeight()};
	KdShaderManager::Instance().m_spriteShader.DrawTex(m_tex01, (long)m_pos.x, (long)m_pos.y, (long)(m_tex01->GetWidth() * m_scale), (long)(m_tex01->GetHeight() * m_scale), &m_rect, nullptr, { 0.0f, 0.5f });

	m_rect = { 0,0,(long)(m_singleW * m_hp),(long)m_tex02->GetHeight() };
	KdShaderManager::Instance().m_spriteShader.DrawTex(m_tex02, (long)m_pos.x, (long)m_pos.y, (long)(m_tex02->GetWidth() * m_scale), (long)(m_tex02->GetHeight() * m_scale), &m_rect, nullptr, { 0.0f, 0.5f });
}
