#pragma once

class Camera;
class Player;
class Monolith;

class BaseHpBar :public KdGameObject
{
public:

	BaseHpBar() {}
	~BaseHpBar()override {}

	void Update()override {}
	void PostUpdate()override {}
	void Init()override {}
	void DrawSprite()override {}

	// セッター
	void SetCamera(const std::weak_ptr<Camera> _camera) { m_camera = _camera; }
	void SetPlayer(const std::weak_ptr<Player> _player) { m_player = _player; }
	void SetMonolith(const std::weak_ptr<Monolith> _monolith) { m_monolith = _monolith; }
	void SetPos(const Math::Vector3 _pos) { m_pos = _pos; }

	// ゲッター
	Math::Vector3 GetPos()const { return m_pos; }

protected:

	std::weak_ptr<Camera> m_camera;
	std::weak_ptr<Player> m_player;
	std::weak_ptr<Monolith> m_monolith;

	std::shared_ptr<KdTexture> m_tex01;
	std::shared_ptr<KdTexture> m_tex02;

	Math::Vector3 m_pos;
	float m_scale = 1.0f;

	Math::Rectangle m_rect;
	Math::Color m_color = { 1.0f,1.0f,1.0f,1.0f };

	float m_dis = 0;

};