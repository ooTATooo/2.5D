#pragma once

class CameraBase :public KdGameObject
{
public:

	CameraBase() {}
	virtual ~CameraBase() override {}

	void Init()override;
	void Update()override;
	void PreDraw()override;

	void SetPlayer(const std::shared_ptr<KdGameObject>& _player) { m_player = _player; }

protected:

	std::shared_ptr<KdCamera> m_camera = nullptr;
	std::weak_ptr<KdGameObject> m_player;

	Math::Matrix m_transMat;
	Math::Matrix m_rotMat;

};