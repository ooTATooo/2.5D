#include "PlayerBullet01.h"

void PlayerBullet01::Update()
{
	//int run[5] = { 0,1,2,3,4 };
	//m_poly->SetUVRect(run[(int)m_anime]);

	//m_anime += 0.1f;
	//if (m_anime >= 5)
	//{
	//	m_anime = 0;
	//}
	m_poly->SetUVRect(0);

	m_moveVec.Normalize();
	m_pos += m_moveVec *= m_moveSpd;
}

void PlayerBullet01::PostUpdate()
{
	// 球判定用の変数を作成
	KdCollider::SphereInfo sphere;
	// 球の中心点を設定
	sphere.m_sphere.Center = m_pos;
	sphere.m_sphere.Center.y += 0.5f;
	// 球の半径を設定
	sphere.m_sphere.Radius = 0.5f;
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
		m_isExpired = true;
	}

	BaseBullet::PostUpdate();
}

void PlayerBullet01::Init()
{
	BaseBullet::Init();

	if (!m_poly)
	{
		m_poly = std::make_shared<KdSquarePolygon>();
		m_poly->SetMaterial("Asset/Textures/PlayerBullet01/bullet.png");
		m_poly->SetSplit(4, 1);
		m_poly->SetPivot(KdSquarePolygon::PivotType::Center_Bottom);
		m_pCollider = std::make_unique<KdCollider>();
		//m_pCollider->RegisterCollisionShape("enemy01", { 0,0.5f,0 }, 0.3f, KdCollider::TypeBump);
	}
}

void PlayerBullet01::shot(Math::Vector3 _playerPos, Math::Vector3 _ground)
{
	m_alive = true;
	m_pos = _playerPos;
	m_moveVec = _ground - m_pos;
	m_moveVec.y = 0;
}
