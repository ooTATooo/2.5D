#include "TrackingCamera.h"

void TrackingCamera::Init()
{
	CameraBase::Init();

	// 基準点(ターゲット)からどれだけ離れているか
	m_transMat = Math::Matrix::CreateTranslation(0, 8, -8);

	// どれだけ傾けているか
	m_rotMat = Math::Matrix::CreateRotationX(DirectX::XMConvertToRadians(45));
}

void TrackingCamera::Update()
{
	// ターゲット
	Math::Matrix pTransMat = Math::Matrix::Identity;
	Math::Vector3 playerPos;

	const std::shared_ptr<const KdGameObject> _target = m_player.lock();
	if (_target)
	{
		pTransMat = _target->GetMatrix();
		playerPos = m_player.lock()->GetPos();
	}

	m_mWorld = m_rotMat * m_transMat * pTransMat;

	UINT scrollType = 0;

	m_mWorld = m_rotMat * m_transMat;

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

	CameraBase::Update();
}
