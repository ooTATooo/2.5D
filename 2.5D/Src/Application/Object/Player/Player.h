#pragma once

class Camera;

class Player :public KdGameObject
{
public:

	enum Dir
	{
		Up = 1 << 0,
		Down = 1 << 1,
		Left = 1 << 2,
		Right = 1 << 3,
	};

	Player() { Init(); }
	~Player()override {}

	void Update()override;
	void PostUpdate()override;
	void Init()override;
	void GenerateDepthMapFromLight()override;
	void DrawLit()override;
	void OnHit()override;

	void Move();
	void MapHit();

	// セッター
	void SetPillar(const std::weak_ptr<KdGameObject> _pillar) { m_pillar = _pillar; }
	void SetGround(const std::weak_ptr<KdGameObject> _ground) { m_ground = _ground; }
	void SetCamera(const std::weak_ptr<Camera> _camera) { m_camera = _camera; }

	// ゲッター
	Math::Vector3 GetPos()const { return m_pos; }
	const Animation::Dir GetDir()const { return m_animeDir; }

private:

	std::shared_ptr<KdSquarePolygon> m_poly = nullptr;

	std::weak_ptr<KdGameObject> m_pillar;
	std::weak_ptr<KdGameObject> m_ground;
	std::weak_ptr<Camera> m_camera;

	float m_moveSpd = 0;
	Math::Vector3 m_pos;
	Math::Vector3 m_moveVec;
	Math::Vector3 m_scale;
	float m_hitWait = 0;
	float m_angX = 0;
	float m_angY = 0;
	UINT m_dir;

	float shotWait= 0;

	Animation::State m_state;
	Animation::Dir m_animeDir;
	std::shared_ptr<Animation> m_anime = nullptr;
	bool m_animeFlg;

};