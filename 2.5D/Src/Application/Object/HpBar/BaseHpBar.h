#pragma once

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

	virtual void SetCamera(std::weak_ptr<KdCamera> _camera) { m_camera = _camera; }
	virtual void SetPlayer(std::weak_ptr<Player> _player) { m_player = _player; }

protected:

	std::weak_ptr<KdCamera> m_camera;
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