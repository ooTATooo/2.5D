#pragma once

class BaseEnemy :public KdGameObject
{
public:

	BaseEnemy() {}
	~BaseEnemy()override {}

	void Update()override;
	void PostUpdate()override;
	void Init()override;
	void GenerateDepthMapFromLight()override;
	void DrawLit()override;

	float Turn();

	void SetPlayer(const std::weak_ptr<KdGameObject> _player) { m_player = _player; }
	void SetBeacon(const std::weak_ptr<KdGameObject> _beacon) { m_beacon = _beacon; }

protected:

	std::shared_ptr<KdSquarePolygon> m_poly = nullptr;

	std::weak_ptr<KdGameObject> m_player;
	std::weak_ptr<KdGameObject> m_beacon;

	float m_moveSpd = 0;
	Math::Vector3 m_pos = m_mWorld.Translation();
	Math::Vector3 m_moveVec = Math::Vector3::Zero;
	Math::Matrix m_rotMatX = Math::Matrix::Identity;
	Math::Matrix m_rotMatY = Math::Matrix::Identity;
	Math::Matrix m_transMat = Math::Matrix::Identity;
	float m_angX = 0;
	float m_angY = 0;
	float m_anime = 0;
};