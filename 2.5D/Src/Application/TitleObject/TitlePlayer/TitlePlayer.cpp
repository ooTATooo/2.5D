#include "TitlePlayer.h"

void TitlePlayer::Update()
{
	m_anime->CreateAnimation("PlayerIdol", m_poly, true);
}

void TitlePlayer::Init()
{
	m_poly = std::make_shared<KdSquarePolygon>();
	m_angX = 20;

	m_anime = std::make_shared<Animation>();

	Math::Matrix m_rotMat = Math::Matrix::CreateRotationX(DirectX::XMConvertToRadians(m_angX));

	//Math::Matrix m_transMat = Math::Matrix::CreateTranslation(m_pos);

	m_mWorld = m_rotMat;// *m_transMat;
}

void TitlePlayer::GenerateDepthMapFromLight()
{
	KdShaderManager::Instance().m_StandardShader.DrawPolygon(*m_poly, m_mWorld);
}

void TitlePlayer::DrawLit()
{
	KdShaderManager::Instance().m_StandardShader.DrawPolygon(*m_poly, m_mWorld);
}
