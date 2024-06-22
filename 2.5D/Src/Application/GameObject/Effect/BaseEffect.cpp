#include "BaseEffect.h"

void BaseEffect::PostUpdate()
{
	Math::Matrix scaleMat = Math::Matrix::CreateScale(m_scale);

	Math::Matrix transMat = Math::Matrix::CreateTranslation(m_pos);

	m_mWorld = scaleMat * transMat;
}

void BaseEffect::Init()
{
	m_pos = Math::Vector3::Zero;
	m_scale = Math::Vector3::One;
	m_dir = Math::Vector3::Zero;

	m_attackArea = 0.3f;
	m_wait = 10;
}

void BaseEffect::DrawUnLit()
{
	KdShaderManager::Instance().m_StandardShader.DrawPolygon(*m_poly, m_mWorld);
}

void BaseEffect::DrawBright()
{
	KdShaderManager::Instance().m_StandardShader.DrawPolygon(*m_poly, m_mWorld);
}
