#include "Pillar.h"

void Pillar::Update()
{
	//std::shared_ptr<KdCamera> camera = m_camera.lock();
	//if (camera)
	//{
	//	// レイの発射方向を求める
	//	Math::Vector3 cameraPos = camera->GetCameraMatrix().Translation();
	//	Math::Vector3 rayDir = Math::Vector3::Zero;
	//	float rayRange = 100.0f;
	//	camera->GenerateRayInfoFromClientPos(mousePos, cameraPos, rayDir, rayRange);

	//	// レイの衝突位置を求める
	//	const std::shared_ptr<KdGameObject> ground = m_ground.lock();
	//	if (ground)
	//	{
	//		Math::Vector3 endRayPos = cameraPos + (rayDir * rayRange);
	//		KdCollider::RayInfo rayInfo(KdCollider::TypeGround, cameraPos, endRayPos);

	//		// 実際の当たり判定処理
	//		std::list<KdCollider::CollisionResult> results;
	//		ground->Intersects(rayInfo, &results);

	//		// 結果が1つでも返って来ていたら
	//		if (results.size())
	//		{
	//			for (auto& result : results)
	//			{
	//				std::shared_ptr<PlayerBullet01> pBullet = std::make_shared<PlayerBullet01>();
	//				pBullet->shot(m_pos, result.m_hitPos);
	//				SceneManager::Instance().AddObject(pBullet);
	//				shotWait = 30;
	//			}
	//		}
	//	}
	//}

}

void Pillar::Init()
{
	m_model = std::make_shared<KdModelData>();
	m_model->Load("Asset/Models/Pillar/Pillar.gltf");

	m_pCollider = std::make_unique<KdCollider>();
	m_pCollider->RegisterCollisionShape("ModelHit", m_model, KdCollider::TypeGround);
}

void Pillar::GenerateDepthMapFromLight()
{
	KdShaderManager::Instance().m_StandardShader.DrawModel(*m_model, m_mWorld, m_color);
}

void Pillar::DrawLit()
{
	KdShaderManager::Instance().m_StandardShader.DrawModel(*m_model, m_mWorld, m_color);
}
