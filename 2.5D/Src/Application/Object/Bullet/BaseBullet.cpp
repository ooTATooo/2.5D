#include "BaseBullet.h"

void BaseBullet::Update()
{
}

void BaseBullet::PostUpdate()
{	
	// 球判定用の変数を作成
	KdCollider::SphereInfo sphere;
	// 球の中心点を設定
	sphere.m_sphere.Center = m_pos;
	sphere.m_sphere.Center.y += 0.5f;
	// 球の半径を設定
	sphere.m_sphere.Radius = 0.3f;
	// 当たり判定をしたいタイプを設定
	sphere.m_type = KdCollider::TypeBump;

	// デバッグ表示
	Math::Color color = { 1,1,0,1 };
	//m_pDebugWire->AddDebugSphere(sphere.m_sphere.Center, sphere.m_sphere.Radius, color);

	m_rotMatX = Math::Matrix::CreateRotationX(DirectX::XMConvertToRadians(m_angX));

	m_rotMatY = Math::Matrix::CreateRotationY(DirectX::XMConvertToRadians(m_angY));

	m_transMat = Math::Matrix::CreateTranslation(m_pos);

	m_mWorld = m_rotMatX * m_rotMatY * m_transMat;
}

void BaseBullet::Init()
{
	m_poly = nullptr;

	m_moveVec = Math::Vector3::Zero;
	m_rotMatX = Math::Matrix::Identity;
	m_rotMatY = Math::Matrix::Identity;
	m_transMat = Math::Matrix::Identity;
	m_pos = Math::Vector3::Zero;
	m_angX = -20;
	m_angY = 0;
	m_moveSpd = 0.1f;
	m_anime = 0;
	m_alive = false;

	m_pDebugWire = std::make_unique<KdDebugWireFrame>();
}

void BaseBullet::GenerateDepthMapFromLight()
{
	if (m_poly)
	{
		KdShaderManager::Instance().m_StandardShader.DrawPolygon(*m_poly, m_mWorld);
	}
}

void BaseBullet::DrawLit()
{
	if (m_poly)
	{
		KdShaderManager::Instance().m_StandardShader.DrawPolygon(*m_poly, m_mWorld);
	}
}
