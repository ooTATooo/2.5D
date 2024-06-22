#include "TitleCamera.h"

void TitleCamera::Init()
{
	m_camera = std::make_shared<KdCamera>();

	Math::Matrix transMat = Math::Matrix::CreateTranslation(3, 5, -5);

	Math::Matrix rotMat = Math::Matrix::CreateRotationX(DirectX::XMConvertToRadians(35));

	m_mWorld = rotMat * transMat;

	m_camera->SetCameraMatrix(m_mWorld);
}

void TitleCamera::PreDraw()
{
	if (!m_camera) return;

	m_camera->SetToShader();
}
