#include "KnightAttack.h"

void KnightAttack::Update()
{
	m_anime->CreateAnimation("KnightAtk", m_poly, false);

	if (!m_anime->GetAnimationFlg())
	{
		m_isExpired = true;
	}
}

void KnightAttack::PostUpdate()
{
	m_wait--;
	if (m_wait < 0)
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
	}

	BaseEffect::PostUpdate();
}

void KnightAttack::Init()
{
	BaseEffect::Init();

	if (!m_poly)
	{
		m_poly = std::make_shared<KdSquarePolygon>();
		m_dir = Animation::Dir::Left;
		m_attackArea = 0.3f;

		m_anime = std::make_shared<Animation>();
	}
}

void KnightAttack::Set(Math::Vector3 _pos, Animation::Dir _dir)
{
	m_pos = _pos;

	if (m_dir != _dir)
	{
		m_scale.x *= -1;
		m_dir = _dir;
	}

	m_wait = 30;

	KdAudioManager::Instance().Play3D("Asset/Sounds/KnightAttack.wav", m_pos, false, 1.0f);
}
