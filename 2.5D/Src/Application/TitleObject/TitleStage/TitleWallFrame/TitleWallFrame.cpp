#include "TitleWallFrame.h"


void TitleWallFrame::Init()
{
	m_model = std::make_shared<KdModelData>();
	m_model->Load("Asset/Models/WallFrame/WallFrame1.gltf");
}

void TitleWallFrame::GenerateDepthMapFromLight()
{
	KdShaderManager::Instance().m_StandardShader.DrawModel(*m_model, m_mWorld);
}

void TitleWallFrame::DrawLit()
{
	KdShaderManager::Instance().m_StandardShader.DrawModel(*m_model, m_mWorld);
}
