#pragma once

class Camera;
class Player;

class BaseHpBar :public KdGameObject
{
public:

	BaseHpBar() {}
	~BaseHpBar()override {}

	void Update()override;
	void PostUpdate()override;
	void Init()override;
	void DrawSprite()override;

	// セッター
	void SetCamera(const std::weak_ptr<Camera> _camera) { m_camera = _camera; }
	void SetPlayer(const std::weak_ptr<Player> _player) { m_player = _player; }
	void SetPos(const Math::Vector3 _pos) { m_pos = _pos; }

	// ゲッター
	const Math::Vector3 GetPos() { return m_pos; }

protected:

	std::weak_ptr<Camera> m_camera;
	std::weak_ptr<Player> m_player;

	struct Data
	{
		std::shared_ptr<KdTexture> tex;
		Math::Matrix scaleMat;
		Math::Matrix transMat;
		Math::Matrix mat;
	};

	Data m_backHp;
	Data m_Hp01;
	Data m_Hp02;

	Math::Vector3 m_pos;
	float m_scale = 1.0f;

	Math::Rectangle m_rect = { 0,0,0,0 };
	Math::Color m_color = { 1.0f,1.0f,1.0f,1.0f };

	float m_dis = 0;

};