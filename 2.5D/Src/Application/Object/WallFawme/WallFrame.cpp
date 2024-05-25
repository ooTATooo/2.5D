#include "WallFrame.h"

void WallFrame::Init()
{
	m_model01 = std::make_shared<KdModelData>();
	m_model01->Load("Asset/Models/WallFrame/WallFrame1.gltf");
	m_model02 = std::make_shared<KdModelData>();
	m_model02->Load("Asset/Models/WallFrame/WallFrame2.gltf");
}

void WallFrame::GenerateDepthMapFromLight()
{
	KdShaderManager::Instance().m_StandardShader.DrawModel(*m_model01, m_mWorld);
	KdShaderManager::Instance().m_StandardShader.DrawModel(*m_model02, m_mWorld, color);
}

void WallFrame::DrawLit()
{
	KdShaderManager::Instance().m_StandardShader.DrawModel(*m_model01, m_mWorld);
	KdShaderManager::Instance().m_StandardShader.DrawModel(*m_model02, m_mWorld, color);
}
