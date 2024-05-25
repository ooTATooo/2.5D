#include "Pillar.h"

void Pillar::Update()
{
}

void Pillar::Init()
{
	m_model = std::make_shared<KdModelData>();
	m_model->Load("Asset/Models/Pillar/Pillar.gltf");
}

void Pillar::GenerateDepthMapFromLight()
{
	KdShaderManager::Instance().m_StandardShader.DrawModel(*m_model, m_mWorld, color);
}

void Pillar::DrawLit()
{
	KdShaderManager::Instance().m_StandardShader.DrawModel(*m_model, m_mWorld, color);
}
