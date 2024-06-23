#include "GameOverBack.h"

void GameOverBack::Update()
{
	m_alpha += m_alphaAdd;
	if (m_alpha > 0.5f)
	{
		m_alpha = 0.5f;
	}
}

void GameOverBack::Init()
{
	BaseUI::Init();

	m_tex = AssetManager::Instance().GetTex("Fade");
	m_pos = Math::Vector3::Zero;
	m_alpha = 0.0f;
	m_alphaAdd = 0.01f;
}

void GameOverBack::DrawSprite()
{
	m_color = { 1,1,1,m_alpha };
	KdShaderManager::Instance().m_spriteShader.DrawTex(m_tex, (int)m_pos.x, (int)m_pos.y,nullptr, &m_color);
}
