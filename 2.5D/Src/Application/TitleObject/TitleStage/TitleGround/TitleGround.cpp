#include "TitleGround.h"

void TitleGround::Init()
{
	m_model = std::make_shared<KdModelData>();
	m_model->Load("Asset/Models/Cobblestone/Cobblestone.gltf");

	TitleBaseStage::Init();
}

void TitleGround::DrawLit()
{
	KdShaderManager::Instance().m_StandardShader.DrawModel(*m_model, m_mWorld);
}
