#include "WallFrame.h"

void WallFrame::Init()
{
	m_model = std::make_shared<KdModelData>();
	m_model->Load("Asset/Models/WallFrame/WallFrame.gltf");
}

void WallFrame::GenerateDepthMapFromLight()
{
	KdShaderManager::Instance().m_StandardShader.DrawModel(*m_model);
}

void WallFrame::DrawLit()
{
	KdShaderManager::Instance().m_StandardShader.DrawModel(*m_model);
}
