#include "Beacon.h"

void Beacon::Init()
{
	m_model = std::make_shared<KdModelData>();
	m_model->Load("Asset/Models/Crystal/Crystal.gltf");
}

void Beacon::GenerateDepthMapFromLight()
{
	KdShaderManager::Instance().m_StandardShader.DrawModel(*m_model, m_mWorld, m_color);
}

void Beacon::DrawLit()
{
	KdShaderManager::Instance().m_StandardShader.DrawModel(*m_model, m_mWorld, m_color);
}

void Beacon::DrawBright()
{
	KdShaderManager::Instance().m_StandardShader.DrawModel(*m_model, m_mWorld, m_color);
}
