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
	m_pos = m_transMat.Translation();
	m_moveVec = Math::Vector3::Zero;

	if (GetAsyncKeyState('W') & 0x8000)
	{
		m_moveVec.z = 1.0f;
	}
	if (GetAsyncKeyState('S') & 0x8000)
	{
		m_moveVec.z = -1.0f;
	}
	if (GetAsyncKeyState('A') & 0x8000)
	{
		m_moveVec.x = -1.0f;
		m_angX = 20;
		m_angY = 0;
	}
	if (GetAsyncKeyState('D') & 0x8000)
	{
		m_moveVec.x = 1.0f;
		m_angX = -20;
		m_angY = 180;
	}

	m_moveVec.Normalize();
	m_moveVec *= m_moveSpd;
	m_pos += m_moveVec;

	frame--;
	if (frame < 0)
	{
		frame = 0;
	}
	if (ani >= 2)
	{
		ani = 0;
	}

	if (m_pos.x < -29.5f) { m_pos.x = -29.5f; }
	if (m_pos.x > 29.5f) { m_pos.x = 29.5f; }
	if (m_pos.z < -29.5f) { m_pos.z = -29.5f; }
	if (m_pos.z > 29.5f) { m_pos.z = 29.5f; }

	m_rotMatX = Math::Matrix::CreateRotationX(DirectX::XMConvertToRadians(m_angX));

	m_rotMatY = Math::Matrix::CreateRotationY(DirectX::XMConvertToRadians(m_angY));

	m_transMat = Math::Matrix::CreateTranslation(m_pos);

	m_mWorld = m_rotMatX * m_rotMatY * m_transMat;

}

void Player::Init()
{
	m_poly = std::make_shared<KdSquarePolygon>();
	m_poly->SetMaterial("Asset/Textures/Player/player.png");
	m_poly->SetSplit(9, 6);
	m_poly->SetPivot(KdSquarePolygon::PivotType::Center_Bottom);
	m_moveSpd = 0.1f;
	m_pos = m_mWorld.Translation();
	m_moveVec = Math::Vector3::Zero;
	m_rotMatX = Math::Matrix::Identity;
	m_rotMatY = Math::Matrix::Identity;
	m_transMat = Math::Matrix::Identity;
	m_size = 1;
	m_angX = -20;
	m_angY = 180;
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
