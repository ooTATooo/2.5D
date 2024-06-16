#include "WallFrame.h"

void WallFrame::PreUpdate()
{
	m_alpha = 1.0f;
}

void WallFrame::Init()
{
	m_model01 = std::make_shared<KdModelData>();
	m_model01->Load("Asset/Models/WallFrame/WallFrame1.gltf");
	m_model02 = std::make_shared<KdModelData>();
	m_model02->Load("Asset/Models/WallFrame/WallFrame2.gltf");
	m_modelHit = std::make_shared<KdModelData>();
	m_modelHit->Load("Asset/Models/WallFrame/WallHit.gltf");

	m_alpha = 1.0f;
	m_color = { 1.0f,1.0f,1.0f,m_alpha };

	m_pCollider = std::make_unique<KdCollider>();
	m_pCollider->RegisterCollisionShape("ModelHit", m_modelHit, KdCollider::TypeGround | KdCollider::TypeAlpha);
}

void WallFrame::GenerateDepthMapFromLight()
{
	m_color = { 1.0f,1.0f,1.0f,m_alpha };
	KdShaderManager::Instance().m_StandardShader.DrawModel(*m_model01, m_mWorld);
	KdShaderManager::Instance().m_StandardShader.DrawModel(*m_model02, m_mWorld, m_color);
}

void WallFrame::DrawLit()
{
	m_color = { 1.0f,1.0f,1.0f,m_alpha };
	KdShaderManager::Instance().m_StandardShader.DrawModel(*m_model01, m_mWorld);
	KdShaderManager::Instance().m_StandardShader.DrawModel(*m_model02, m_mWorld, m_color);
}

void WallFrame::Hit()
{
	m_alpha = 0.3f;
}
