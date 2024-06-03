#include "Pillar.h"

void Pillar::Update()
{
}

void Pillar::Init()
{
	m_model = std::make_shared<KdModelData>();
	m_model->Load("Asset/Models/Pillar/Pillar.gltf");

	m_pCollider = std::make_unique<KdCollider>();
	m_pCollider->RegisterCollisionShape("ModelHit", m_model, KdCollider::TypeBump);
}

void Pillar::GenerateDepthMapFromLight()
{
	KdShaderManager::Instance().m_StandardShader.DrawModel(*m_model, m_mWorld, m_color);
}

void Pillar::DrawLit()
{
	KdShaderManager::Instance().m_StandardShader.DrawModel(*m_model, m_mWorld, m_color);
}
