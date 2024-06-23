#include "WaveTex.h"

void WaveTex::Update()
{
	if (!m_alphaFlg)
	{
		m_alpha += m_alphaAdd;
		if (m_alpha > 1)
		{
			m_alpha = 1.0f;
			m_frameFlg = true;
		}
	}
	else
	{
		m_alpha -= m_alphaAdd;
		if (m_alpha < 0)
		{
			m_isExpired = true;
		}
	}

	if (m_frameFlg)
	{
		m_frame--;
		if (m_frame <= 0)
		{
			m_alphaFlg = true;
		}
	}
}

void WaveTex::Init()
{
	BaseUI::Init();

	m_pos = { 0,200,0 };
	m_alpha = 0.0f;
	m_alphaAdd = 0.01f;
	m_frame = 60;
	m_frameFlg = false;
	m_alphaFlg = false;
}

void WaveTex::DrawSprite()
{
	m_color = { 1,1,1,m_alpha };
	KdShaderManager::Instance().m_spriteShader.DrawTex(m_tex, (int)m_pos.x, (int)m_pos.y,nullptr, &m_color);
}

void WaveTex::SetWave(EnemyManager::WaveType _wave)
{
	m_wave = _wave;

	switch (m_wave)
	{
	case EnemyManager::WaveType::First:
		m_tex = AssetManager::Instance().GetTex("First");
		break;
	case EnemyManager::WaveType::Second:
		m_tex = AssetManager::Instance().GetTex("Second");
		break;
	case EnemyManager::WaveType::Final:
		m_tex = AssetManager::Instance().GetTex("Final");
		break;
	}
}
