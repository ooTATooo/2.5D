#include "BossHp.h"

#include "../../Camera/Camera.h"
#include "../../Player/Player.h"

void BossHp::Update()
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
}

void BossHp::PostUpdate()
{
	Math::Vector3 barRes = Math::Vector3::Zero;
	std::shared_ptr<Camera> camera = m_camera.lock();
	if (camera)
	{
		barRes = camera->GetConvertWorldToScreenDetail(m_pos);// + Math::Vector3{ -0.8f,2.5f,0 });
	}

	m_backHp.transMat = Math::Matrix::CreateTranslation(barRes.x, barRes.y, 0);
	m_backHp.scaleMat = Math::Matrix::CreateScale(m_scale);
	m_backHp.mat = m_backHp.scaleMat * m_backHp.transMat;

	m_Hp01.transMat = Math::Matrix::CreateTranslation(barRes.x, barRes.y, 0);
	m_Hp01.scaleMat = Math::Matrix::CreateScale(m_scale);
	m_Hp01.mat = m_Hp01.scaleMat * m_Hp01.transMat;

	m_Hp02.transMat = Math::Matrix::CreateTranslation(barRes.x, barRes.y, 0);
	m_Hp02.scaleMat = Math::Matrix::CreateScale(m_scale);
	m_Hp02.mat = m_Hp02.scaleMat * m_Hp02.transMat;
}

void BossHp::Init()
{
	m_backHp.tex = std::make_shared<KdTexture>();
	m_backHp.tex = AssetManager::Instance().GetTex("BarBack");
	m_backHp.scaleMat = Math::Matrix::CreateScale(m_scale);
	m_backHp.transMat = Math::Matrix::Identity;

	m_Hp01.tex = std::make_shared<KdTexture>();
	m_Hp01.tex = AssetManager::Instance().GetTex("Bar");
	m_Hp01.scaleMat = Math::Matrix::CreateScale(m_scale);
	m_Hp01.transMat = Math::Matrix::Identity;

	m_Hp02.tex = std::make_shared<KdTexture>();
	m_Hp02.tex = AssetManager::Instance().GetTex("Bar");
	m_Hp02.scaleMat = Math::Matrix::CreateScale(m_scale);
	m_Hp02.transMat = Math::Matrix::Identity;
}

void BossHp::DrawSprite()
{
	m_rect = { 0,0,(int)m_backHp.tex->GetWidth(),(int)m_backHp.tex->GetHeight() };
	m_color = { 1.0f,1.0f,1.0f,1.0f };
	KdShaderManager::Instance().m_spriteShader.SetMatrix(m_backHp.mat);
	KdShaderManager::Instance().m_spriteShader.DrawTex(m_backHp.tex, 0, 0, m_backHp.tex->GetWidth(), m_backHp.tex->GetHeight(), &m_rect, &m_color, { 0.0f, 0.5f });

	m_rect = { 0,0,(int)m_Hp01.tex->GetWidth(),(int)m_Hp01.tex->GetHeight() };
	m_color = { 1.0f,1.0f,0.0f,1.0f };
	KdShaderManager::Instance().m_spriteShader.SetMatrix(m_Hp01.mat);
	KdShaderManager::Instance().m_spriteShader.DrawTex(m_Hp01.tex, 0, 0, m_Hp01.tex->GetWidth(), m_Hp01.tex->GetHeight(), &m_rect, &m_color, { 0.0f, 0.5f });

	m_rect = { 0,0,(int)m_Hp02.tex->GetWidth(),(int)m_Hp02.tex->GetHeight() };
	m_color = { 0.0f,1.0f,0.0f,1.0f };
	KdShaderManager::Instance().m_spriteShader.SetMatrix(m_Hp02.mat);
	KdShaderManager::Instance().m_spriteShader.DrawTex(m_Hp02.tex, 0, 0, m_Hp02.tex->GetWidth(), m_Hp02.tex->GetHeight(), &m_rect, &m_color, { 0.0f, 0.5f });
}
