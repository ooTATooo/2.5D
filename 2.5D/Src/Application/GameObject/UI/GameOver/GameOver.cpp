﻿#include "GameOver.h"

#include"../../Effect/Fade/Fade.h"

void GameOver::Update()
{
	m_alpha += m_alphaAdd;
	if (m_alpha > 1)
	{
		m_alpha = 1.0f;
		m_frameFlg = true;
	}

	if (m_frameFlg)
	{
		m_frame--;
		if (m_frame <= 0)
		{
			m_changeFlg = true;
		}
	}

	if (m_changeFlg)
	{
		Fade::Instance().BootFade(SceneManager::SceneType::Title);		
	}
}

void GameOver::Init()
{
	BaseUI::Init();

	m_tex = AssetManager::Instance().GetTex("GameOver");
	m_pos = { 0,200,0 };
	m_alpha = 0.0f;
	m_alphaAdd = 0.01f;
	m_frame = 120;
	m_frameFlg = false;
	m_changeFlg = false;
}

void GameOver::DrawSprite()
{
	m_color = { 1,1,1,m_alpha };
	KdShaderManager::Instance().m_spriteShader.DrawTex(m_tex, (int)m_pos.x, (int)m_pos.y,nullptr, &m_color);
}
