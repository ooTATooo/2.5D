#include "BaseUI.h"

void BaseUI::PostUpdate()
{
	Math::Matrix m_scaleMat = Math::Matrix::CreateScale(m_scale);

	Math::Matrix m_transMat = Math::Matrix::CreateTranslation(m_pos);

	m_mWorld = m_scaleMat * m_transMat;
}

void BaseUI::Init()
{
	if (!m_tex)
	{
		m_tex = std::make_shared<KdTexture>();
	}
}

void BaseUI::DrawSprite()
{
	m_rect = { 0,0,(long)m_tex->GetWidth(),(long)m_tex->GetHeight() };
	m_color = { 1,1,1,1 };
	KdShaderManager::Instance().m_spriteShader.DrawTex(m_tex, 0, 0, &m_rect, &m_color);
}
