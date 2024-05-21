#include "Skeleton.h"

void Skeleton::Update()
{
	m_scaleMat = Math::Matrix::CreateScale(m_size);

	m_rotMat = Math::Matrix::CreateRotationY(DirectX::XMConvertToRadians(m_ang));

	m_trancMat = Math::Matrix::CreateTranslation(m_nowPos);

	m_mWorld = m_scaleMat * m_rotMat * m_trancMat;
}

void Skeleton::Init()
{
	m_model.Load("Asset/Models/Skeleton/skeleton.gltf");
	m_moveSpd = 0.1f;
	m_nowPos = m_mWorld.Translation();
	m_moveVec = Math::Vector3::Zero;
	m_scaleMat = Math::Matrix::Identity;
	m_rotMat = Math::Matrix::Identity;
	m_trancMat = Math::Matrix::Identity;
	m_size = 0.2f;
	m_ang = 0;
}

void Skeleton::GenerateDepthMapFromLight()
{
	KdShaderManager::Instance().m_StandardShader.DrawModel(m_model, m_mWorld);
}

void Skeleton::DrawLit()
{
	KdShaderManager::Instance().m_StandardShader.DrawModel(m_model, m_mWorld);
}