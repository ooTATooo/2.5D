#include "CameraBase.h"

void CameraBase::Init()
{
	m_camera = std::make_shared<KdCamera>();
}

void CameraBase::Update()
{
	m_camera->SetCameraMatrix(m_mWorld);
}

void CameraBase::PreDraw()
{
	m_camera->SetToShader();
}
