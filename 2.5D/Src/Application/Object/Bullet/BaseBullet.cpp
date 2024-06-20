#include "BaseBullet.h"

void BaseBullet::PostUpdate()
{
	// 球判定用の変数を作成
	KdCollider::SphereInfo sphere;
	// 球の中心点を設定
	sphere.m_sphere.Center = m_pos;
	sphere.m_sphere.Center.y += 0.5f;
	// 球の半径を設定
	sphere.m_sphere.Radius = 0.5f;
	// 当たり判定をしたいタイプを設定
	sphere.m_type = KdCollider::TypeGround | KdCollider::TypeWall;

	// デバッグ表示
	Math::Color color = { 1,1,0,1 };
	m_pDebugWire->AddDebugSphere(sphere.m_sphere.Center, sphere.m_sphere.Radius, color);

	// 球に当たったオブジェクトの情報を格納
	std::list<KdCollider::CollisionResult> retSphereList;

	// 当たり判定
	for (auto& obj : SceneManager::Instance().GetObjList())
	{
		if (obj->Intersects(sphere, &retSphereList))
		{
			OnHit();
		}
	}

	Math::Matrix scaleMat = Math::Matrix::CreateScale(m_scale);

	Math::Matrix transMat = Math::Matrix::CreateTranslation(m_pos);

	m_mWorld = scaleMat * transMat;
}

void BaseBullet::Init()
{
	m_poly = nullptr;

	m_moveSpd = 0.1f;
	m_moveVec = Math::Vector3::Zero;

	m_pos = Math::Vector3::Zero;
	m_scale = Math::Vector3::One;

	m_alive = false;

	m_pDebugWire = std::make_unique<KdDebugWireFrame>();
}

void BaseBullet::DrawLit()
{
	KdShaderManager::Instance().m_StandardShader.DrawPolygon(*m_poly, m_mWorld);
}

void BaseBullet::DrawBright()
{
	KdShaderManager::Instance().m_StandardShader.DrawPolygon(*m_poly, m_mWorld);
}

void BaseBullet::shot(Math::Vector3 _startPos, Math::Vector3 _targetPos)
{
	m_alive = true;
	m_pos = _startPos;
	m_moveVec = _targetPos - m_pos;
	m_moveVec.y = 0;
	m_moveVec.Normalize();
	if (m_moveVec.x > 0) { m_scale.x *= -1; }
}
