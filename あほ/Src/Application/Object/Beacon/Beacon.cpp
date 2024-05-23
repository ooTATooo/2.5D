#include "Beacon.h"

void Beacon::Init()
{
	m_model = std::make_shared<KdModelData>();
	m_model->Load("Asset/Models/Beacon/Beacon.gltf");
	m_mWorld = Math::Matrix::CreateScale(4);
}

void Beacon::GenerateDepthMapFromLight()
{
	KdShaderManager::Instance().m_StandardShader.DrawModel(*m_model, m_mWorld);
}

void Beacon::DrawLit()
{
	KdShaderManager::Instance().m_StandardShader.DrawModel(*m_model, m_mWorld);
}
