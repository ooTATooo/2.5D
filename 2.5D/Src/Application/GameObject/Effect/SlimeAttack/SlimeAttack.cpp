#include "SlimeAttack.h"

void SlimeAttack::Update()
{
	m_wait--;
	if (m_wait <= 0)
	{
		m_isExpired = true;
	}
}

void SlimeAttack::PostUpdate()
{
	// 球判定用の変数を作成
	KdCollider::SphereInfo sphere;
	// 球の中心点を設定
	sphere.m_sphere.Center = m_pos;
	sphere.m_sphere.Center.y += 0.5f;
	// 球の半径を設定
	sphere.m_sphere.Radius = m_attackArea;
	// 当たり判定をしたいタイプを設定
	sphere.m_type = KdCollider::TypePlayer | KdCollider::TypeMonolith;

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

void SlimeAttack::Init()
{
	BaseEffect::Init();

	if (!m_poly)
	{
		m_poly = std::make_shared<KdSquarePolygon>();
		m_attackArea = 0.3f;

		KdAudioManager::Instance().Play("Asset/Sounds/SlimeAttack.wav", false, 0.3f);
	}
}

void SlimeAttack::Set(Math::Vector3 _startPos, Math::Vector3 _targetPos)
{
	m_pos = _startPos;
	m_dir = _targetPos - _startPos;
	m_dir.y = 0;
	m_dir.Normalize();
	m_pos += m_dir * 0.7f;
	m_wait = 30;
}
