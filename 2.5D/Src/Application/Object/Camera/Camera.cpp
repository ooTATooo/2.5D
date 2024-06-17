#include "Camera.h"

#include "../Player/Player.h"

void Camera::Init()
{
	m_camera = std::make_shared<KdCamera>();

	// 基準点(ターゲット)からどれだけ離れているか
	m_transMat = Math::Matrix::CreateTranslation(0, 8, -8);

	// どれだけ傾けているか
	m_rotMat = Math::Matrix::CreateRotationX(DirectX::XMConvertToRadians(45));
}

void Camera::Update()
{
	if (!m_camera) return;


}

void Camera::PostUpdate()
{
	// ターゲット
	Math::Matrix pTransMat;
	Math::Vector3 playerPos;

	const std::shared_ptr<const Player> player = m_player.lock();
	if (player)
	{
		pTransMat = player->GetMatrix();
		playerPos = player->GetPos();
	}

	Hit(playerPos);

	UINT scrollType = 0;

	m_mWorld = m_rotMat * m_transMat;

	// スクロールの限界処理
	if (playerPos.z > 27.0f) { scrollType |= ScrollType::Up; }
	if (playerPos.z < -27.0f) { scrollType |= ScrollType::Down; }
	if (playerPos.x < -26.0f) { scrollType |= ScrollType::Left; }
	if (playerPos.x > 26.0f) { scrollType |= ScrollType::Right; }

	if (scrollType & ScrollType::Up) { pTransMat = Math::Matrix::CreateTranslation(playerPos.x, playerPos.y, 27.0f); }
	if (scrollType & ScrollType::Down) { pTransMat = Math::Matrix::CreateTranslation(playerPos.x, playerPos.y, -27.0f); }
	if (scrollType & ScrollType::Left) { pTransMat = Math::Matrix::CreateTranslation(-26.0f, playerPos.y, playerPos.z); }
	if (scrollType & ScrollType::Right) { pTransMat = Math::Matrix::CreateTranslation(26.0f, playerPos.y, playerPos.z); }

	if (scrollType == (ScrollType::Up | ScrollType::Left)) { pTransMat = Math::Matrix::CreateTranslation(-26.0f, playerPos.y, 27.0f); }
	if (scrollType == (ScrollType::Up | ScrollType::Right)) { pTransMat = Math::Matrix::CreateTranslation(26.0f, playerPos.y, 27.0f); }
	if (scrollType == (ScrollType::Down | ScrollType::Left)) { pTransMat = Math::Matrix::CreateTranslation(-26.0f, playerPos.y, -27.0f); }
	if (scrollType == (ScrollType::Down | ScrollType::Right)) { pTransMat = Math::Matrix::CreateTranslation(26.0f, playerPos.y, -27.0f); }

	if (scrollType == 0) { pTransMat = Math::Matrix::CreateTranslation(playerPos); }

	m_mWorld *= pTransMat;

	m_camera->SetCameraMatrix(m_mWorld);
}

void Camera::PreDraw()
{
	if (!m_camera) return;

	m_camera->SetToShader();
}

void Camera::Hit(Math::Vector3 _playerPos)
{
	Math::Vector3 dir;
	dir = _playerPos - m_camera->GetCameraMatrix().Translation();

	// レイ判定用に変数を作成
	KdCollider::RayInfo ray;

	// レイの発射位置(座標)を設定
	ray.m_pos = m_camera->GetCameraMatrix().Translation();

	// レイの長さを設定
	ray.m_range = dir.Length();

	dir.Normalize();

	// レイの発射方向
	ray.m_dir = dir;

	// 当たり判定をしたいタイプを設定
	ray.m_type = KdCollider::TypeAlpha;

	// レイに当たったオブジェクト情報を格納
	std::list<KdCollider::CollisionResult> retrayList;

	// 当たり判定
	for (auto& obj : SceneManager::Instance().GetObjList())
	{
		if (obj->Intersects(ray, &retrayList))
		{
			obj->OnHit();
			break;
		}
	}
}

const Math::Vector3 Camera::GetConvertWorldToScreenDetail(const Math::Vector3 _pos)
{
	Math::Vector3 barRes = Math::Vector3::Zero;
	m_camera->ConvertWorldToScreenDetail(_pos, barRes);
	return barRes;
}

const Math::Vector3 Camera::GetPos()
{
	Math::Vector3 pos = Math::Vector3::Zero;
	pos = m_camera->GetCameraMatrix().Translation();
	return pos;
}
