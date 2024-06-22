#include "WallFrame.h"

void WallFrame::PreUpdate()
{
	if (!m_alphaFlg)
	{
		m_alpha += m_alphaSpd;
		if (m_alpha >= 1.0f)
		{
			m_alpha = 1.0f;
		}
	}
	m_alphaFlg = false;
}

void WallFrame::Init()
{
	m_model01 = std::make_shared<KdModelData>();
	m_model01->Load("Asset/Models/WallFrame/WallFrame1.gltf");
	m_model02 = std::make_shared<KdModelData>();
	m_model02->Load("Asset/Models/WallFrame/WallFrame2.gltf");
	m_modelHit = std::make_shared<KdModelData>();
	m_modelHit->Load("Asset/Models/WallFrame/WallHit.gltf");

	BaseStage::Init();

	m_pCollider = std::make_unique<KdCollider>();
	m_pCollider->RegisterCollisionShape("ModelHit", m_modelHit, KdCollider::TypeWall | KdCollider::TypeAlpha);
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

void WallFrame::OnHit()
{
	m_alphaFlg = true;
	if (m_alpha > 0.2f)
	{
		m_alpha -= m_alphaSpd;
	}
}
