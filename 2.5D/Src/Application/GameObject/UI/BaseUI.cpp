#include "BaseUI.h"

void BaseUI::Init()
{
	if (!m_tex)
	{
		m_tex = std::make_shared<KdTexture>();
	}
}

void BaseUI::DrawSprite()
{
	KdShaderManager::Instance().m_spriteShader.DrawTex(m_tex, (int)m_pos.x, (int)m_pos.y, nullptr, nullptr);
}
