#include "TitleStart.h"

void TitleStart::Update()
{
	m_alpha += m_alphaAdd;
	if (m_alpha > 1)
	{
		m_alpha = 1.0f;
		m_alphaAdd *= -1;
	}
	if (m_alpha < 0.3)
	{
		m_alpha = 0.3f;
		m_alphaAdd *= -1;
	}
}

void TitleStart::Init()
{
	m_tex = AssetManager::Instance().GetTex("TitleStart");

	m_pos = { 300,-200,0 };
}

void TitleStart::DrawSprite()
{
	m_color = { 1,1,1,m_alpha };
	KdShaderManager::Instance().m_spriteShader.DrawTex(m_tex, (long)m_pos.x, (long)m_pos.y, nullptr, &m_color);
}
