#include "BeaconHp.h"

void BeaconHp::Update()
{
	Math::Vector3 res = Math::Vector3::Zero;
	m_camera.lock()->ConvertWorldToScreenDetail(m_mWorld.Translation(), res);

	m_backHp.transMat = Math::Matrix::CreateTranslation(res);
	m_backHp.mat = m_backHp.scaleMat * m_backHp.transMat;

	m_yellowHp.transMat = Math::Matrix::CreateTranslation(res);
	m_yellowHp.mat = m_yellowHp.scaleMat * m_yellowHp.transMat;

	m_greenHp.transMat = Math::Matrix::CreateTranslation(res);
	m_greenHp.mat = m_greenHp.scaleMat * m_greenHp.transMat;
}

void BeaconHp::Init()
{
	m_backHp.tex.Load("Asset/Textures/HpBar/hpbar01.png");
	m_backHp.scaleMat = Math::Matrix::CreateScale(0.25f, 0.25f, 0.25f);
	m_backHp.transMat = Math::Matrix::Identity;

	m_yellowHp.tex.Load("Asset/Textures/HpBar/hpbar02.png");
	m_yellowHp.scaleMat = Math::Matrix::CreateScale(0.25f, 0.25f, 0.25f);
	m_yellowHp.transMat = Math::Matrix::Identity;

	m_greenHp.tex.Load("Asset/Textures/HpBar/hpbar02.png");
	m_greenHp.scaleMat = Math::Matrix::CreateScale(0.25f, 0.25f, 0.25f);
	m_greenHp.transMat = Math::Matrix::Identity;
}

void BeaconHp::DrawSprite()
{
	Math::Rectangle rect = { 0,0,420,36 };
	Math::Color color = { 1.0f,1.0f,1.0f,1.0f };
	KdShaderManager::Instance().m_spriteShader.SetMatrix(m_backHp.mat);
	KdShaderManager::Instance().m_spriteShader.DrawTex(&m_backHp.tex, 0, 0, 420, 36, &rect, &color);

	rect = { 0,0,414,30 };
	color = { 1.0f,1.0f,0.0f,1.0f };
	KdShaderManager::Instance().m_spriteShader.SetMatrix(m_yellowHp.mat);
	KdShaderManager::Instance().m_spriteShader.DrawTex(&m_yellowHp.tex, 0, 0, 414, 30, &rect, &color);

	color = { 0.0f,1.0f,0.0f,1.0f };
	KdShaderManager::Instance().m_spriteShader.SetMatrix(m_greenHp.mat);
	KdShaderManager::Instance().m_spriteShader.DrawTex(&m_greenHp.tex, 0, 0, 414, 30, &rect,&color);
}
