#include "Camera.h"

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

	// ターゲット
	Math::Matrix pTransMat;
	Math::Vector3 playerPos;

	const std::shared_ptr<const KdGameObject> player = m_player.lock();
	if (player)
	{
		pTransMat = player->GetMatrix();
		playerPos = player->GetPos();
	}

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

const Math::Vector3 Camera::GetConvertWorldToScreenDetail(const Math::Vector3 _pos)
{
	Math::Vector3 barRes = Math::Vector3::Zero;
	m_camera->ConvertWorldToScreenDetail(_pos, barRes);
	return barRes;
}
