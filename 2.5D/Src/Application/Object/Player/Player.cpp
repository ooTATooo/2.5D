#include "Player.h"

void Player::Update()
{
	m_moveSpd = 0.1f;
	m_nowPos = m_trancMat.Translation();
	m_moveVec = Math::Vector3::Zero;

	KeyAction();

	m_moveVec.Normalize();
	m_moveVec *= m_moveSpd;
	m_nowPos += m_moveVec;

	m_scaleMat = Math::Matrix::CreateScale(m_size);

	m_rotMat = Math::Matrix::CreateRotationY(DirectX::XMConvertToRadians(m_ang));

	m_trancMat = Math::Matrix::CreateTranslation(m_nowPos);

	m_mWorld = m_scaleMat * m_rotMat * m_trancMat;
}

void Player::Init()
{
	m_model.Load("Asset/Models/Player/KnightCharacter.gltf");
	m_moveSpd = 0.1f;
	m_nowPos = m_mWorld.Translation();
	m_moveVec = Math::Vector3::Zero;
	m_scaleMat = Math::Matrix::Identity;
	m_rotMat = Math::Matrix::Identity;
	m_trancMat = Math::Matrix::Identity;
	m_size = 0.25f;
	m_ang = 0;
	for (int i = 0; i < keyType::kind; i++)
	{
		m_keyFlg[i] = false;
	}
}

void Player::GenerateDepthMapFromLight()
{
	KdShaderManager::Instance().m_StandardShader.DrawModel(m_model, m_mWorld);
}

void Player::DrawLit()
{
	KdShaderManager::Instance().m_StandardShader.DrawModel(m_model, m_mWorld);
}

void Player::KeyAction()
{
	for (int i = 0; i < keyType::kind; i++)
	{
		m_keyFlg[i] = false;
	}

	if (GetAsyncKeyState('W') & 0x8000)
	{
		m_keyFlg[keyType::W] = true;
		m_moveVec.z = 1.0f;
		m_ang = 180;
	}
	if (GetAsyncKeyState('S') & 0x8000)
	{
		m_keyFlg[keyType::S] = true;
		m_moveVec.z = -1.0f;
		m_ang = 0;
	}
	if (GetAsyncKeyState('A') & 0x8000)
	{
		m_keyFlg[keyType::A] = true;
		m_moveVec.x = -1.0f;
		m_ang = 90;
	}
	if (GetAsyncKeyState('D') & 0x8000)
	{
		m_keyFlg[keyType::D] = true;
		m_moveVec.x = 1.0f;
		m_ang = 270;
	}

	if (m_keyFlg[keyType::W] && m_keyFlg[keyType::A])
	{
		m_ang = 135;
	}
	if (m_keyFlg[keyType::W] && m_keyFlg[keyType::D])
	{
		m_ang = 225;
	}
	if (m_keyFlg[keyType::S] && m_keyFlg[keyType::A])
	{
		m_ang = 45;
	}
	if (m_keyFlg[keyType::S] && m_keyFlg[keyType::D])
	{
		m_ang = 315;
	}
}
