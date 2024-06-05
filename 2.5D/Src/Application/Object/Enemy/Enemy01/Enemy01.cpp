#include "Enemy01.h"

void Enemy01::Update()
{
	int run[3] = { 9,10,11 };
	m_poly->SetUVRect(run[(int)m_anime]);

	m_anime += 0.1f;
	if (m_anime >= 3)
	{
		m_anime = 0;
	}

	m_moveVec = Math::Vector3::Zero;

	const std::shared_ptr<KdGameObject> beacon = m_beacon.lock();

	// 対象座標ー自分の座標
	Math::Vector3 dis;
	dis = beacon->GetPos() - m_pos;

	m_moveVec = dis;

	// 球判定・・・ベクトルの長さで判定
	if (dis.Length() < 3.0f)
	{
		// ビーコン前で止まる
		m_moveVec = Math::Vector3::Zero;
	}

	m_moveVec.Normalize();
	m_pos += m_moveVec *= m_moveSpd;
}

void Enemy01::PostUpdate()
{
	m_rotMatX = Math::Matrix::CreateRotationX(DirectX::XMConvertToRadians(m_angX));

	m_rotMatY = Math::Matrix::CreateRotationY(DirectX::XMConvertToRadians(m_angY));

	m_transMat = Math::Matrix::CreateTranslation(m_pos);

	m_mWorld = m_rotMatX * m_rotMatY * m_transMat;
}

void Enemy01::Init()
{
	BaseEnemy::Init();

	if (!m_poly)
	{
		m_poly = std::make_shared<KdSquarePolygon>();
		m_poly->SetMaterial("Asset/Textures/Enemy01/slime01.png");
		m_poly->SetSplit(12, 1);
		m_poly->SetPivot(KdSquarePolygon::PivotType::Center_Bottom);
		m_poly->SetScale(1);
		m_pos = { -5,0,-21 };
		m_angX = -20;
		m_angY = 180;
		m_moveSpd = 0.02f;
	}
}