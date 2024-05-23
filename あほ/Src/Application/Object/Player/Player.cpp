#include "Player.h"

void Player::Update()
{
	if (frame == 0)
	{
		frame = 20;
		ani++;
	}
	m_poly->SetUVRect(ani);

	m_moveSpd = 0.1f;
	m_nowPos = m_trancMat.Translation();
	m_moveVec = Math::Vector3::Zero;

	KeyAction();

	m_moveVec.Normalize();
	m_moveVec *= m_moveSpd;
	m_nowPos += m_moveVec;

	frame--;
	if (frame < 0)
	{
		frame = 0;
	}
	if (ani >= 2)
	{
		ani = 0;
	}

	m_rotMatX = Math::Matrix::CreateRotationX(DirectX::XMConvertToRadians(m_angX));

	m_rotMatY = Math::Matrix::CreateRotationY(DirectX::XMConvertToRadians(m_angY));

	m_trancMat = Math::Matrix::CreateTranslation(m_nowPos);

	m_mWorld = m_rotMatX * m_rotMatY * m_trancMat;
}

void Player::Init()
{
	m_poly = std::make_shared<KdSquarePolygon>();
	m_poly->SetMaterial("Asset/Textures/Player/player.png");
	m_poly->SetSplit(9, 6);
	m_poly->SetPivot(KdSquarePolygon::PivotType::Center_Bottom);
	m_moveSpd = 0.1f;
	m_nowPos = m_mWorld.Translation();
	m_moveVec = Math::Vector3::Zero;
	m_rotMatX = Math::Matrix::Identity;
	m_rotMatY = Math::Matrix::Identity;
	m_trancMat = Math::Matrix::CreateTranslation(0.0f, 0.0f, 0.0f);
	m_size = 1;
	m_angX = -20;
	m_angY = 180;
	for (int i = 0; i < keyType::kind; i++)
	{
		m_keyFlg[i] = false;
	}


	frame = 0;
	ani = 0;
}

void Player::GenerateDepthMapFromLight()
{
	KdShaderManager::Instance().m_StandardShader.DrawPolygon(*m_poly, m_mWorld);
}

void Player::DrawLit()
{
	KdShaderManager::Instance().m_StandardShader.DrawPolygon(*m_poly, m_mWorld);
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
	}
	if (GetAsyncKeyState('S') & 0x8000)
	{
		m_keyFlg[keyType::S] = true;
		m_moveVec.z = -1.0f;
	}
	if (GetAsyncKeyState('A') & 0x8000)
	{
		m_keyFlg[keyType::A] = true;
		m_moveVec.x = -1.0f;
		m_angX = 20;
		m_angY = 0;
	}
	if (GetAsyncKeyState('D') & 0x8000)
	{
		m_keyFlg[keyType::D] = true;
		m_moveVec.x = 1.0f;
		m_angX = -20;
		m_angY = 180;
	}
}
