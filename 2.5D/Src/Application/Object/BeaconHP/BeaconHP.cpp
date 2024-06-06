#include "BeaconHp.h"

#include "../Player/Player.h"

void BeaconHp::Update()
{
	const std::shared_ptr<KdGameObject> player = m_player.lock();

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

	ImGuiManager::Instance().SetSize(m_scale);
}

void BeaconHp::PostUpdate()
{
	Math::Vector3 barRes = Math::Vector3::Zero;
	if (!m_camera.expired())
	{
		m_camera.lock()->ConvertWorldToScreenDetail(m_pos, barRes);
	}

	m_backHp.transMat = Math::Matrix::CreateTranslation(barRes.x, barRes.y, 0);
	m_backHp.scaleMat = Math::Matrix::CreateScale(m_scale);
	m_backHp.mat = m_backHp.scaleMat * m_backHp.transMat;

	m_yellowHp.transMat = Math::Matrix::CreateTranslation(barRes.x, barRes.y, 0);
	m_yellowHp.scaleMat = Math::Matrix::CreateScale(m_scale);
	m_yellowHp.mat = m_yellowHp.scaleMat * m_yellowHp.transMat;

	m_greenHp.transMat = Math::Matrix::CreateTranslation(barRes.x, barRes.y, 0);
	m_greenHp.scaleMat = Math::Matrix::CreateScale(m_scale);
	m_greenHp.mat = m_greenHp.scaleMat * m_greenHp.transMat;
}

void BeaconHp::Init()
{
	m_backHp.tex.Load("Asset/Textures/HpBar/hpbar01.png");
	m_backHp.scaleMat = Math::Matrix::CreateScale(m_scale);
	m_backHp.transMat = Math::Matrix::Identity;

	m_yellowHp.tex.Load("Asset/Textures/HpBar/hpbar02.png");
	m_yellowHp.scaleMat = Math::Matrix::CreateScale(m_scale);
	m_yellowHp.transMat = Math::Matrix::Identity;

	m_greenHp.tex.Load("Asset/Textures/HpBar/hpbar02.png");
	m_greenHp.scaleMat = Math::Matrix::CreateScale(m_scale);
	m_greenHp.transMat = Math::Matrix::Identity;

	m_pos = m_mWorld.Translation() + Math::Vector3{ -1,2.5f,0 };
}

void BeaconHp::DrawSprite()
{

	m_rect = { 0,0,(int)m_backHp.tex.GetWidth(),(int)m_backHp.tex.GetHeight() };
	m_color = { 1.0f,1.0f,1.0f,1.0f };
	KdShaderManager::Instance().m_spriteShader.SetMatrix(m_backHp.mat);
	KdShaderManager::Instance().m_spriteShader.DrawTex(&m_backHp.tex, 0, 0, m_backHp.tex.GetWidth(), m_backHp.tex.GetHeight(), &m_rect, &m_color, { 0.0f, 0.5f });

	m_rect = { 0,0,(int)m_yellowHp.tex.GetWidth(),(int)m_yellowHp.tex.GetHeight() };
	m_color = { 1.0f,1.0f,0.0f,1.0f };
	KdShaderManager::Instance().m_spriteShader.SetMatrix(m_yellowHp.mat);
	KdShaderManager::Instance().m_spriteShader.DrawTex(&m_yellowHp.tex, 0, 0, m_yellowHp.tex.GetWidth(), m_yellowHp.tex.GetHeight(), &m_rect, &m_color, { 0.0f, 0.5f });

	m_rect = { 0,0,(int)m_greenHp.tex.GetWidth(),(int)m_greenHp.tex.GetHeight() };
	m_color = { 0.0f,1.0f,0.0f,1.0f };
	KdShaderManager::Instance().m_spriteShader.SetMatrix(m_greenHp.mat);
	KdShaderManager::Instance().m_spriteShader.DrawTex(&m_greenHp.tex, 0, 0, m_greenHp.tex.GetWidth(), m_greenHp.tex.GetHeight(), &m_rect, &m_color, { 0.0f, 0.5f });
}
