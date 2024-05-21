#include "PlayerHp.h"

void PlayerHp::Update()
{
	m_backHp.mat = Math::Matrix::CreateTranslation(m_backHp.pos);

	m_yellowHp.mat = Math::Matrix::CreateTranslation(m_yellowHp.pos);

	m_greenHp.mat = Math::Matrix::CreateTranslation(m_greenHp.pos);
}

void PlayerHp::Init()
{
	m_backHp.tex.Load("Asset/Textures/PlayerHP/hpbar01.png");
	m_backHp.mat = Math::Matrix::Identity;
	m_backHp.pos = { -600,-300,0 };

	m_yellowHp.tex.Load("Asset/Textures/PlayerHP/hpbar02.png");
	m_yellowHp.mat = Math::Matrix::Identity;
	m_yellowHp.pos = { -597,-300,0 };

	m_greenHp.tex.Load("Asset/Textures/PlayerHP/hpbar03.png");
	m_greenHp.mat = Math::Matrix::Identity;
	m_greenHp.pos = { -597,-300,0 };
}

void PlayerHp::DrawSprite()
{
	Math::Rectangle rect = { 0,0,420,36 };
	Math::Color color = { 1.0f,1.0f,1.0f,1.0f };
	KdShaderManager::Instance().m_spriteShader.SetMatrix(m_backHp.mat);
	KdShaderManager::Instance().m_spriteShader.DrawTex(&m_backHp.tex, 0, 0, 420, 36, &rect, &color, { 0.0f, 0.5f });

	rect = { 0,0,414,30 };
	color = { 1.0f,1.0f,1.0f,1.0f };
	KdShaderManager::Instance().m_spriteShader.SetMatrix(m_yellowHp.mat);
	KdShaderManager::Instance().m_spriteShader.DrawTex(&m_yellowHp.tex, 0, 0, 414, 30, &rect, &color, { 0.0f, 0.5f });

	KdShaderManager::Instance().m_spriteShader.SetMatrix(m_greenHp.mat);
	KdShaderManager::Instance().m_spriteShader.DrawTex(&m_greenHp.tex, 0, 0, 414, 30, &rect, &color, { 0.0f, 0.5f });
}
