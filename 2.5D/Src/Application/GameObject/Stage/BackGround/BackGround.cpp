#include "BackGround.h"

void BackGround::Init()
{
	m_poly = std::make_shared<KdSquarePolygon>();
	*m_poly = AssetManager::Instance().GetMaterial("BackGround");
	m_mWorld = Math::Matrix::CreateTranslation(0, 0, 35.0f);
}

void BackGround::DrawUnLit()
{
	KdShaderManager::Instance().m_StandardShader.DrawPolygon(*m_poly, m_mWorld);
}
