﻿#include "BaseEnemy.h"

#include "../Effect/AttackImpact/AttackImpact.h"

void BaseEnemy::PreUpdate()
{
	if (m_dissolve >= 1.0f)
	{
		m_isExpired = true;
	}
}

void BaseEnemy::Update()
{
	m_hitWait--;
	if (m_hitWait <= 0) { m_hitWait = 0; }

	m_moveVec.Normalize();

	if (m_moveVec.x < 0) { m_dir = Animation::Dir::Left; }
	else if (m_moveVec.x > 0) { m_dir = Animation::Dir::Right; }

	if (m_alive)
	{
		m_pos += m_moveVec *= m_moveSpd;
	}

	if (m_oldDir != m_dir)
	{
		m_scale.x *= -1;
		m_oldDir = m_dir;
	}
}

void BaseEnemy::PostUpdate()
{
	MapHit();

	Math::Matrix scaleMat = Math::Matrix::CreateScale(m_scale);

	Math::Matrix rotMat = Math::Matrix::CreateRotationX(DirectX::XMConvertToRadians(m_angX));

	Math::Matrix transMat = Math::Matrix::CreateTranslation(m_pos);

	m_mWorld = scaleMat * rotMat * transMat;
}

void BaseEnemy::Init()
{
	m_angX = 30;
	m_moveSpd = 0.02f;

	m_alive = true;
	m_animeFlg = false;
	m_dir = Animation::Dir::Left;
	m_oldDir = m_dir;
	m_state = Animation::State::None;

	m_pDebugWire = std::make_unique<KdDebugWireFrame>();
}

void BaseEnemy::GenerateDepthMapFromLight()
{
	if (m_poly)
	{
		KdShaderManager::Instance().m_StandardShader.DrawPolygon(*m_poly, m_mWorld);
	}
}

void BaseEnemy::DrawLit()
{
	if (m_poly)
	{
		if (!m_alive)
		{
			Dissolve();
		}

		KdShaderManager::Instance().m_StandardShader.DrawPolygon(*m_poly, m_mWorld);
	}
}

void BaseEnemy::OnHit()
{
	if (m_hp <= 0)
	{
		m_alive = false;

		m_state = Animation::State::Die;
	}
	else
	{
		if (m_hitWait <= 0)
		{
			m_state = Animation::State::Hit;

			std::shared_ptr<AttackImpact> atkImpact = std::make_shared<AttackImpact>();
			atkImpact->Set(m_pos);
			SceneManager::Instance().AddObject(atkImpact);

			m_hp--;
			m_hitWait = 60;
		}
	}
}

void BaseEnemy::MapHit()
{
	// 球判定用の変数を作成
	KdCollider::SphereInfo sphere;
	// 球の中心点を設定
	sphere.m_sphere.Center = m_pos;
	sphere.m_sphere.Center.y += 0.5f;
	// 球の半径を設定
	sphere.m_sphere.Radius = 0.3f;
	// 当たり判定をしたいタイプを設定
	sphere.m_type = KdCollider::TypeGround;

	// 球に当たったオブジェクトの情報を格納
	std::list<KdCollider::CollisionResult> retSphereList;

	// 当たり判定
	for (auto& obj : SceneManager::Instance().GetObjList())
	{
		obj->Intersects(sphere, &retSphereList);
	}

	// 球に当たったリストから一番近いオブジェクトを検出
	float maxOverLap = 0;	// はみでたレイの長さ
	Math::Vector3 hitDir;	// 当たった方向
	bool isHit = false;		// 当たっていたらtrue
	for (auto& ret : retSphereList)
	{
		// 球にめりこんで、オーバーした長さが一番長いものを探す
		if (maxOverLap < ret.m_overlapDistance)
		{
			maxOverLap = ret.m_overlapDistance;
			hitDir = ret.m_hitDir;
			isHit = true;
		}
	}

	if (isHit)
	{
		// yへの押し返し無効
		hitDir.y = 0;
		// 正規化(長さを１にする)
		// 方向は絶対長さ１
		hitDir.Normalize();

		// 地面に当たっている
		m_pos += hitDir * maxOverLap;
	}
}

void BaseEnemy::Dissolve()
{
	m_dissolve += 0.01f;
	KdShaderManager::Instance().m_StandardShader.SetDissolve(m_dissolve);
}
