#include "Pillar.h"

void Pillar::PreUpdate()
{
	m_alpha = 1.0f;
}

void Pillar::Init()
{
	m_model = std::make_shared<KdModelData>();
	m_model->Load("Asset/Models/Pillar/Pillar.gltf");

	m_alpha = 1.0f;
	m_color = { 1.0f,1.0f,1.0f,m_alpha };

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

void Pillar::Hit()
{
	m_alpha = 0.5f;
}
