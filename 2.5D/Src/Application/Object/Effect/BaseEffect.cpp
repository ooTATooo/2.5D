#include "BaseEffect.h"

void BaseEffect::Update()
{
}

void BaseEffect::PostUpdate()
{
	Math::Matrix scaleMat = Math::Matrix::CreateScale(m_scale);

	Math::Matrix transMat = Math::Matrix::CreateTranslation(m_pos);

	m_mWorld = scaleMat * transMat;
}

void BaseEffect::Init()
{
	m_pos = {};
	m_attackArea = 0.3f;
}

void BaseEffect::DrawUnLit()
{
	KdShaderManager::Instance().m_StandardShader.DrawPolygon(*m_poly, m_mWorld);
}

void BaseEffect::DrawBright()
{
	KdShaderManager::Instance().m_StandardShader.DrawPolygon(*m_poly, m_mWorld);
}
