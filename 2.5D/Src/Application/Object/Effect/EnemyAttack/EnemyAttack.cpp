#include "EnemyAttack.h"

#include "../../Player/Player.h"

void EnemyAttack::Update()
{
	m_anime->CreateAnimation("PlayerAtkEffect", m_poly, false);

	if (!m_anime->GetAnimationFlg())
	{
		m_isExpired = true;
	}
}

void EnemyAttack::PostUpdate()
{
	// 球判定用の変数を作成
	KdCollider::SphereInfo sphere;
	// 球の中心点を設定
	sphere.m_sphere.Center = m_pos;
	sphere.m_sphere.Center.y += 0.5f;
	// 球の半径を設定
	sphere.m_sphere.Radius = m_attackArea;
	// 当たり判定をしたいタイプを設定
	sphere.m_type = KdCollider::TypeDamage;

	// デバッグ表示
	m_pDebugWire->AddDebugSphere(sphere.m_sphere.Center, sphere.m_sphere.Radius, kRedColor);

	std::list<KdCollider::CollisionResult> retSphereList;

	bool hit = false;
	for (auto& obj : SceneManager::Instance().GetObjList())
	{
		hit = obj->Intersects(sphere, &retSphereList);

		if (hit)
		{
			obj->OnHit();
			break;
		}
	}

	BaseEffect::PostUpdate();
}

void EnemyAttack::Init()
{
	BaseEffect::Init();

	if (!m_poly)
	{
		m_poly = std::make_shared<KdSquarePolygon>();
		m_anime = std::make_shared<Animation>();
		m_scale = { 2,2,2 };
		m_dir = Animation::Dir::Left;
		m_attackArea = 1.0f;

		m_pDebugWire = std::make_unique<KdDebugWireFrame>();
	}
}

void EnemyAttack::Set(Math::Vector3 _pos, Animation::Dir _dir)
{
	m_pos = _pos;

	if (m_dir != _dir)
	{
		m_scale.x *= -1;
		m_dir = _dir;
	}
}
