#pragma once

class Monolith;
class Player;

class BaseEnemy :public KdGameObject
{
public:

	BaseEnemy() { Init(); }
	~BaseEnemy()override {}

	void PreUpdate()override;
	void Update()override;
	void PostUpdate()override;
	void Init()override;
	void GenerateDepthMapFromLight()override;
	void DrawLit()override;
	void OnHit()override;

	void MapHit();
	void Dissolve();

	void SetPlayer(const std::weak_ptr<KdGameObject> _player) { m_player = _player; }
	void SetBeacon(const std::weak_ptr<KdGameObject> _monolith) { m_monolith = _monolith; }

	void SetPos(const Math::Vector3 _pos) { m_pos = _pos; }

	Math::Vector3 GetPos()const { return m_pos; }
	bool GetAlive()const { return m_alive; }


protected:

	std::shared_ptr<KdSquarePolygon> m_poly = nullptr;

	std::weak_ptr<KdGameObject> m_player;
	std::weak_ptr<KdGameObject> m_monolith;

	Math::Vector3 m_pos = Math::Vector3::Zero;
	Math::Vector3 m_moveVec = Math::Vector3::Zero;
	Math::Vector3 m_scale = Math::Vector3::One;
	float m_moveSpd;
	float m_angX;
	float m_hitWait = 0;
	int m_maxHp;
	int m_hp;

	float m_dissolve = 0;
	bool m_alive = false;

	Animation::Dir m_dir;
	Animation::Dir m_oldDir;
	Animation::State m_state;
	std::shared_ptr<Animation> m_anime = nullptr;
	bool m_animeFlg;
};