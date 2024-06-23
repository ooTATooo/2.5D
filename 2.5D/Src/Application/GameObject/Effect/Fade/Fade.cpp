#include "Fade.h"

void Fade::Update()
{
    if (m_bFadeOut)
    {
        m_blackAlpha += 0.008f;
        if (m_blackAlpha >= 1.0f)
        {
            m_bFadeOut = false;
            m_blackAlpha = 1.0f;
            SceneManager::Instance().SetNextScene(m_nextScene);
            m_bFadeIn = true;
        }
        m_blackColor = { 1.0f,1.0f,1.0f,m_blackAlpha };
    }

    if (m_bFadeIn)
    {
        m_blackAlpha -= 0.008f;
        if (m_blackAlpha <= 0.0f)
        {
            m_bFadeIn = false;
            m_blackAlpha = 0.0f;
            m_bFade = false;
        }
        m_blackColor = { 1.0f,1.0f,1.0f,m_blackAlpha };
    }
}

void Fade::DrawSprite()
{
    KdShaderManager::Instance().m_spriteShader.DrawTex(m_tex, 0, 0, nullptr, &m_blackColor);
}

void Fade::BootFade(SceneManager::SceneType _type)
{
    m_bFade = true;
    m_bFadeOut = true;
    m_nextScene = _type;
}

void Fade::Init()
{
	m_tex = std::make_shared<KdTexture>();
	m_tex = AssetManager::Instance().GetTex("Fade");
    m_blackAlpha = 0.0f;
    m_blackColor = { 1.0f,1.0f,1.0f,m_blackAlpha };
    m_bFade = false;
    m_bFadeOut = false;
    m_bFadeIn = false;
}