#include "Player.h"

#include "../../Scene/SceneManager.h"

void Player::Update()
{
	int run[3] = { 0,1,2 };
	m_poly->SetUVRect(run[(int)m_anime]);

	m_anime += 0.1f;
	if (m_anime >= 3)
	{
		m_anime = 0;
	}

	//m_pos = m_transMat.Translation();
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
	m_pos += m_moveVec *= m_moveSpd;
}

void Player::PostUpdate()
{
	// =====================
	// 当たり判定(レイ判定)
	// =====================

	// レイ判定用に変数を作成
	KdCollider::RayInfo ray;
	// レイの発射位置(座標)を設定
	ray.m_pos = m_pos;	// 自分の足元
	// レイの発射方法
	ray.m_dir = Math::Vector3::Forward;
	// 少し高いところから飛ばす
	ray.m_pos.y += 0.5f;
	// 段差の許容範囲を設定
	//float enableStepHigh = 0.2f;
	//ray.m_pos.y += enableStepHigh;

	// レイの長さを設定
	ray.m_range = 3.0f;// m_gravity + enableStepHigh;
	// 当たり判定をしたいタイプを設定
	ray.m_type = KdCollider::TypeGround;

	// デバッグ表示
	Math::Color color = { 1,1,1,1 };
	m_pDebugWire->AddDebugLine(ray.m_pos, ray.m_dir, ray.m_range, color);

	// レイに当たったオブジェクト情報を格納するリスト
	std::list<KdCollider::CollisionResult> retRayList;

	// レイと当たり判定！！
	for (auto& obj : SceneManager::Instance().GetObjList())
	{
		obj->Intersects(ray, &retRayList);
	}

	// レイに当たったリストから一番近いオブジェクトを検出
	float maxOverLap = 0;	// はみでたレイの長さ
	bool isHit = false;		// 当たっていたらtrue
	for (auto& ret : retRayList)
	{
		// レイを遮断し、オーバーした長さが一番長いものを探す
		if (maxOverLap < ret.m_overlapDistance)
		{
			isHit = true;
		}
	}

	if (isHit)
	{
		// オブジェクトに隠れている

	}

	MapHit();

	m_rotMatX = Math::Matrix::CreateRotationX(DirectX::XMConvertToRadians(m_angX));

	m_rotMatY = Math::Matrix::CreateRotationY(DirectX::XMConvertToRadians(m_angY));

	m_transMat = Math::Matrix::CreateTranslation(m_pos);

	m_mWorld = m_rotMatX * m_rotMatY * m_transMat;

}

void Player::Init()
{
	//AssetManager::Instance().CallPolygon("Player");
	m_poly = std::make_shared<KdSquarePolygon>();
	m_poly->SetMaterial("Asset/Textures/Player/player.png");
	m_poly->SetSplit(9, 6);
	m_poly->SetPivot(KdSquarePolygon::PivotType::Center_Bottom);
	m_moveSpd = 0.1f;
	m_pos = { 0,0,0 };
	m_moveVec = Math::Vector3::Zero;
	m_rotMatX = Math::Matrix::Identity;
	m_rotMatY = Math::Matrix::Identity;
	m_transMat = Math::Matrix::Identity;
	m_angX = -20;
	m_angY = 180;
	m_anime = 0;

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
