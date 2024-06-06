#pragma once

#include "../BaseBullet.h"

class PlayerBullet01 :public BaseBullet
{
public:

	PlayerBullet01() { Init(); }
	~PlayerBullet01()override {}

	void Update()override;
	void PostUpdate()override;
	void Init()override;

	void shot(Math::Vector3 _playerPos, Math::Vector3 _mousePos);
private:

	Math::Vector3 m_playerPos = Math::Vector3::Zero;
	Math::Vector3 m_mousePos = Math::Vector3::Zero;
};