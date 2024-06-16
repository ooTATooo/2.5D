#pragma once

class Player;

class Camera :public KdGameObject
{
public:

	// スクロール限界
	enum ScrollType
	{
		Up = 1 << 0,
		Down = 1 << 1,
		Left = 1 << 2,
		Right = 1 << 3,
	};

	Camera() { Init(); }
	~Camera() override {}

	void Init()override;
	void Update()override;
	void PostUpdate()override;
	void PreDraw()override;

	void Hit(Math::Vector3 _playerPos);

	// セッター
	void SetPlayer(const std::shared_ptr<Player> _player) { m_player = _player; }

	// ゲッター
	const std::shared_ptr<KdCamera> GetCamera() { return m_camera; }
	const Math::Vector3 GetConvertWorldToScreenDetail(const Math::Vector3 _pos);
	const Math::Vector3 GetPos();

private:

	std::shared_ptr<KdCamera> m_camera = nullptr;
	std::weak_ptr<Player> m_player;

	Math::Matrix m_transMat;
	Math::Matrix m_rotMat;

};