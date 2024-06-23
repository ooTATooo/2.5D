#include "WhiteFade.h"

void WhiteFade::Update()
{
    if (m_bFadeOut)
    {
		m_alpha += 0.008f;
        if (m_alpha >= 1.0f)
        {
            m_bFadeOut = false;
			m_alpha = 1.0f;
            SceneManager::Instance().SetNextScene(m_nextScene);
            m_bFadeIn = true;
        }
		m_color = { 1.0f,1.0f,1.0f,m_alpha };
    }

    if (m_bFadeIn)
    {
		m_alpha -= 0.008f;
        if (m_alpha <= 0.0f)
        {
            m_bFadeIn = false;
			m_alpha = 0.0f;
            m_bFade = false;
        }
		m_color = { 1.0f,1.0f,1.0f,m_alpha };
    }
}

void WhiteFade::DrawSprite()
{
    KdShaderManager::Instance().m_spriteShader.DrawTex(m_tex, 0, 0, nullptr, &m_color);
}

void WhiteFade::BootFade(SceneManager::SceneType _type)
{
    m_bFade = true;
    m_bFadeOut = true;
    m_nextScene = _type;
}

void WhiteFade::Init()
{
	m_tex = std::make_shared<KdTexture>();
	m_tex = AssetManager::Instance().GetTex("WhiteFade");
	m_alpha = 0.0f;
	m_color = { 1.0f,1.0f,1.0f,m_alpha };
    m_bFade = false;
    m_bFadeOut = false;
    m_bFadeIn = false;
}