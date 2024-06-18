#pragma once

class Monolith;
class Player;

class BaseEnemy :public KdGameObject
{
public:

	BaseEnemy() {}
	~BaseEnemy()override {}

	void Update()override {}
	void PostUpdate()override;
	void Init()override;
	void GenerateDepthMapFromLight()override;
	void DrawLit()override;
	void OnHit()override {}

	void MapHit();
	void SetPlayer(const std::weak_ptr<Player> _player) { m_player = _player; }
	void SetBeacon(const std::weak_ptr<Monolith> _monolith) { m_monolith = _monolith; }

	const Math::Vector3 GetPos()const { return m_pos; }

protected:

	std::shared_ptr<KdSquarePolygon> m_poly = nullptr;

	std::weak_ptr<Player> m_player;
	std::weak_ptr<Monolith> m_monolith;

	float m_moveSpd = 0;
	Math::Vector3 m_pos = Math::Vector3::Zero;
	Math::Vector3 m_moveVec = Math::Vector3::Zero;
	Math::Matrix m_rotMatX = Math::Matrix::Identity;
	Math::Matrix m_rotMatY = Math::Matrix::Identity;
	Math::Matrix m_transMat = Math::Matrix::Identity;
	float m_angX = 0;
	float m_angY = 0;

	Animation::State m_state;
	std::shared_ptr<Animation> m_anime = nullptr;
	bool m_animeFlg;
};