#pragma once

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
	virtual ~Camera() override {}

	void Init()override;
	void Update()override;
	void PreDraw()override;

	// セッター
	void SetPlayer(const std::shared_ptr<KdGameObject>& _player) { m_player = _player; }

	// ゲッター
	const Math::Vector3 GetConvertWorldToScreenDetail(const Math::Vector3 _pos);

protected:

	std::shared_ptr<KdCamera> m_camera = nullptr;
	std::weak_ptr<KdGameObject> m_player;

	Math::Matrix m_transMat;
	Math::Matrix m_rotMat;

};