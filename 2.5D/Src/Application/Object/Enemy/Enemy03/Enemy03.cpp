#include "Enemy03.h"

void Enemy03::Update()
{
	int run[4] = { 10,11,12,13 };
	m_poly->SetUVRect(run[(int)m_anime]);

	m_anime += 0.1f;
	if (m_anime >= 4)
	{
		m_anime = 0;
	}

	m_rotMatX = Math::Matrix::CreateRotationX(DirectX::XMConvertToRadians(m_angX));

	m_rotMatY = Math::Matrix::CreateRotationY(DirectX::XMConvertToRadians(m_angY));

	m_transMat = Math::Matrix::CreateTranslation(m_pos);

	m_mWorld = m_rotMatX * m_rotMatY * m_transMat;
}

void Enemy03::Init()
{
	BaseEnemy::Init();

	if (!m_poly)
	{
		m_poly = std::make_shared<KdSquarePolygon>();
		m_poly->SetMaterial("Asset/Textures/Enemy03/knight01.png");
		m_poly->SetSplit(14, 1);
		m_poly->SetPivot(KdSquarePolygon::PivotType::Center_Bottom);
		m_poly->SetScale(2);
		m_pos = { 3,0,0 };
		m_angX = -20;
		m_angY = 180;
	}
}