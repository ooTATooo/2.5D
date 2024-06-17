﻿#include "Player.h"

#include "../Camera/Camera.h"
#include "../Bullet/PlayerBullet01/PlayerBullet01.h"

void Player::Update()
{
	switch (m_state)
	{
	case AnimationManager::CharaState::Idol:
		m_anime->CreateCharaAnimation("Player", m_state, m_dir, m_poly);
		break;
	case AnimationManager::CharaState::Attack:
		m_anime->CreateCharaAnimation("Player", m_state, m_dir, m_poly);
		break;
	case AnimationManager::CharaState::Run:
		m_anime->CreateCharaAnimation("Player", m_state, m_dir, m_poly);
		break;
	}

	Move();

	ShotBullet();
}

void Player::PostUpdate()
{
	MapHit();

	EnemyHit();

	ImGuiManager::Instance().SetPlayerPos(m_pos);

	Math::Matrix m_rotMat = Math::Matrix::CreateRotationX(DirectX::XMConvertToRadians(m_angX));

	Math::Matrix m_transMat = Math::Matrix::CreateTranslation(m_pos);

	m_mWorld = m_rotMat * m_transMat;

}

void Player::Init()
{
	m_poly = std::make_shared<KdSquarePolygon>();
	m_moveSpd = 0.1f;
	m_pos = { 10,0,-2 };
	m_moveVec = Math::Vector3::Zero;
	m_angX = 20;

	m_anime = std::make_shared<AnimationManager>();
	m_state = AnimationManager::CharaState::Idol;
	m_dir = AnimationManager::Dir::Left;

	m_pCollider = std::make_unique<KdCollider>();
	m_pCollider->RegisterCollisionShape("player", { 0,0.5f,0 }, 0.3f, KdCollider::TypeBump);

	// デバッグ用
	m_pDebugWire = std::make_unique<KdDebugWireFrame>();
}

void Player::GenerateDepthMapFromLight()
{
	KdShaderManager::Instance().m_StandardShader.DrawPolygon(*m_poly, m_mWorld);
}

void Player::DrawLit()
{
	KdShaderManager::Instance().m_StandardShader.DrawPolygon(*m_poly, m_mWorld);
}

void Player::Move()
{
	m_state = AnimationManager::CharaState::Idol;

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
		m_state = AnimationManager::CharaState::Idol;
		m_dir = AnimationManager::Dir::Left;
	}
	if (GetAsyncKeyState('D') & 0x8000)
	{
		m_moveVec.x = 1.0f;
		m_state = AnimationManager::CharaState::Idol;
		m_dir = AnimationManager::Dir::Right;
	}

	m_moveVec.Normalize();
	m_pos += m_moveVec *= m_moveSpd;
}

void Player::MapHit()
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

	// デバッグ表示
	Math::Color color = { 1,1,0,1 };
	m_pDebugWire->AddDebugSphere(sphere.m_sphere.Center, sphere.m_sphere.Radius, color);

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

void Player::EnemyHit()
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

	// 球に当たったオブジェクトの情報を格納
	std::list<KdCollider::CollisionResult> retSphereList;

	for (auto& obj : SceneManager::Instance().GetObjList())
	{
		if (obj->Intersects(sphere, &retSphereList))
		{
			obj->OnHit();
		}
	}

	//// 当たり判定
	//for (auto& obj : SceneManager::Instance().GetObjList())
	//{
	//	obj->Intersects(sphere, &retSphereList);
	//}

	//// 球に当たったリストから一番近いオブジェクトを検出
	//float maxOverLap = 0;	// はみでたレイの長さ
	//Math::Vector3 hitDir;	// 当たった方向
	//bool isHit = false;		// 当たっていたらtrue
	//for (auto& ret : retSphereList)
	//{
	//	// 球にめりこんで、オーバーした長さが一番長いものを探す
	//	if (maxOverLap < ret.m_overlapDistance)
	//	{
	//		maxOverLap = ret.m_overlapDistance;
	//		hitDir = ret.m_hitDir;
	//		isHit = true;
	//	}
	//}

	//if (isHit)
	//{
	//	// yへの押し返し無効
	//	hitDir.y = 0;
	//	// 正規化(長さを１にする)
	//	// 方向は絶対長さ１
	//	hitDir.Normalize();

	//	// 地面に当たっている
	//	m_pos += hitDir * maxOverLap;
	//}
}

void Player::ShotBullet()
{
	if (shotWait <= 0)
	{
		if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
		{
			POINT mousePos;
			GetCursorPos(&mousePos);
			ScreenToClient(Application::Instance().GetWindowHandle(), &mousePos);

			std::shared_ptr<Camera> camera = m_camera.lock();
			if (camera)
			{
				// レイの発射方向を求める
				Math::Vector3 cameraPos = camera->GetPos();
				Math::Vector3 rayDir = Math::Vector3::Zero;
				float rayRange = 100.0f;
				camera->GetCamera()->GenerateRayInfoFromClientPos(mousePos, cameraPos, rayDir, rayRange);

				// レイの衝突位置を求める
				const std::shared_ptr<KdGameObject> ground = m_ground.lock();
				if (ground)
				{
					Math::Vector3 endRayPos = cameraPos + (rayDir * rayRange);
					KdCollider::RayInfo rayInfo(KdCollider::TypeGround, cameraPos, endRayPos);

					// 実際の当たり判定処理
					std::list<KdCollider::CollisionResult> results;
					ground->Intersects(rayInfo, &results);

					// 結果が1つでも返って来ていたら
					if (results.size())
					{
						for (auto& result : results)
						{
							std::shared_ptr<PlayerBullet01> pBullet = std::make_shared<PlayerBullet01>();
							pBullet->shot(m_pos, result.m_hitPos);
							SceneManager::Instance().AddObject(pBullet);
							shotWait = 30;
						}
					}
				}
			}
		}
	}

	shotWait--;
	if (shotWait == 0)
	{
		shotWait = 0;
	}
}
