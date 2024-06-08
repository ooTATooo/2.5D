#pragma once

class Player :public KdGameObject
{
public:

	Player() { Init(); }
	~Player()override {}

	void Update()override;
	void PostUpdate()override;
	void Init()override;
	void GenerateDepthMapFromLight()override;
	void DrawLit()override;

	void MapHit();

	void SetPillar(const std::weak_ptr<KdGameObject> _pillar) { m_pillar = _pillar; }
	void SetGround(const std::weak_ptr<KdGameObject> _ground) { m_ground = _ground; }
	void SetCamera(const std::weak_ptr<KdCamera> _camera) { m_camera = _camera; }

private:

	std::shared_ptr<KdSquarePolygon> m_poly = nullptr;

	std::weak_ptr<KdGameObject> m_pillar;
	std::weak_ptr<KdGameObject> m_ground;
	std::weak_ptr<KdCamera> m_camera;

	float m_moveSpd = 0;
	Math::Vector3 m_pos = Math::Vector3::Zero;;
	Math::Vector3 m_moveVec = Math::Vector3::Zero;
	Math::Matrix m_rotMatX = Math::Matrix::Identity;
	Math::Matrix m_rotMatY = Math::Matrix::Identity;
	Math::Matrix m_transMat = Math::Matrix::Identity;
	float m_angX = 0;
	float m_angY = 0;

	float m_anime = 0;

	float shotWait= 0;

};