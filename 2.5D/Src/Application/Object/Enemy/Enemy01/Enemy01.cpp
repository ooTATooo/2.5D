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
		m_pos = { 1,0,0 };
		m_angX = -20;
		m_angY = 180;
	}
}