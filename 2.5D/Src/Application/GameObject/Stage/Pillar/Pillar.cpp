#include "Pillar.h"

void Pillar::PreUpdate()
{
	if (!m_alphaFlg)
	{
		m_alpha += m_alphaSpd;
		if (m_alpha >= 1.0f)
		{
			m_alpha = 1.0f;
		}
	}
	m_alphaFlg = false;
}

void Pillar::Init()
{
	m_model = std::make_shared<KdModelData>();
	m_model->Load("Asset/Models/Pillar/Pillar.gltf");

	BaseStage::Init();

	m_pCollider = std::make_unique<KdCollider>();
	m_pCollider->RegisterCollisionShape("ModelHit", m_model, KdCollider::TypeGround | KdCollider::TypeAlpha);

}

void Pillar::GenerateDepthMapFromLight()
{
	m_color = { 1.0f,1.0f,1.0f,m_alpha };
	KdShaderManager::Instance().m_StandardShader.DrawModel(*m_model, m_mWorld, m_color);
}

void Pillar::DrawLit()
{
	m_color = { 1.0f,1.0f,1.0f,m_alpha };
	KdShaderManager::Instance().m_StandardShader.DrawModel(*m_model, m_mWorld, m_color);
}

void Pillar::OnHit()
{
	m_alphaFlg = true;
	if (m_alpha > 0.5f)
	{
		m_alpha -= m_alphaSpd;
	}
}
