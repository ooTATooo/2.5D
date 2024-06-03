#include "BeaconHp.h"

#include "../Player/Player.h"

void BeaconHp::Update()
{
	Math::Vector3 barRes = Math::Vector3::Zero;
	if (!m_camera.expired())
	{
		m_camera.lock()->ConvertWorldToScreenDetail(m_pos, barRes);
	}

	if (!m_player.expired())
	{
		if (m_player.lock()->GetPos().z < 0)
		{
			m_scale = 1.0f - (m_player.lock()->GetPos().z / -29.0f);
		}
		if (m_player.lock()->GetPos().z > 0)
		{
			m_scale = 1.0f + (m_player.lock()->GetPos().z / 29.0f);
		}
	}

	ImGuiManager::Instance().SetSize(m_scale);

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

	m_pos = m_mWorld.Translation() + Math::Vector3{ 0,2.5f,0 };
}

void BeaconHp::DrawSprite()
{

	m_rect = { 0,0,105,9 };
	m_color = { 1.0f,1.0f,1.0f,1.0f };
	KdShaderManager::Instance().m_spriteShader.SetMatrix(m_backHp.mat);
	KdShaderManager::Instance().m_spriteShader.DrawTex(&m_backHp.tex, 0, 0, 105, 9, &m_rect, &m_color);

	m_rect = { 0,0,103,7 };
	m_color = { 1.0f,1.0f,0.0f,1.0f };
	KdShaderManager::Instance().m_spriteShader.SetMatrix(m_yellowHp.mat);
	KdShaderManager::Instance().m_spriteShader.DrawTex(&m_yellowHp.tex, 0, 0, 103, 7, &m_rect, &m_color);

	m_color = { 0.0f,1.0f,0.0f,1.0f };
	KdShaderManager::Instance().m_spriteShader.SetMatrix(m_greenHp.mat);
	KdShaderManager::Instance().m_spriteShader.DrawTex(&m_greenHp.tex, 0, 0, 103, 7, &m_rect,&m_color);
}
