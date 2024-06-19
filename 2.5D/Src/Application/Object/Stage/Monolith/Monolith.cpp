#include "Monolith.h"

#include "../../Camera/Camera.h"
#include "../../HpBar/MonolithHp/MonolithHP.h"

void Monolith::Update()
{
	m_pos.y = sin(DirectX::XMConvertToRadians(m_ang)) * m_speed;

	m_ang += 2.0f;
	if (m_ang >= 360.0f)
	{
		m_ang = 0.0f;
	}

	m_color01 = { 0.5f,1,1,alpha + sin(DirectX::XMConvertToRadians(m_ang)) / 10 };
}

void Monolith::PostUpdate()
{
	m_mWorld = Math::Matrix::CreateTranslation(m_pos);
}

void Monolith::Init()
{
	m_model01 = std::make_shared<KdModelData>();
	m_model01->Load("Asset/Models/Monument/Monument1.gltf");

	m_model02 = std::make_shared<KdModelData>();
	m_model02->Load("Asset/Models/Monument/Monument2.gltf");

	m_pos = {};
	m_ang = 0;
	m_speed = 0.15f;

	m_objType = KdGameObject::ObjType::Monolith;

	alpha = 0.3f;
	m_color01 = { 0.5f,1,1,alpha };
	m_color02 = { 0,0,0,1 };

	m_pCollider = std::make_unique<KdCollider>();
	m_pCollider->RegisterCollisionShape("Monolith", m_model01, KdCollider::TypeGround);

}

void Monolith::GenerateDepthMapFromLight()
{
	KdShaderManager::Instance().m_StandardShader.DrawModel(*m_model01, m_mWorld, m_color01);
	KdShaderManager::Instance().m_StandardShader.DrawModel(*m_model02, m_mWorld, m_color02);
}

void Monolith::DrawLit()
{
	KdShaderManager::Instance().m_StandardShader.DrawModel(*m_model01, m_mWorld, m_color01);
	KdShaderManager::Instance().m_StandardShader.DrawModel(*m_model02, m_mWorld, m_color02);
}

void Monolith::DrawBright()
{
	KdShaderManager::Instance().m_StandardShader.DrawModel(*m_model01, m_mWorld, m_color01);
}
