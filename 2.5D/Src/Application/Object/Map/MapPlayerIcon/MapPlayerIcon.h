#pragma once

#include "../BaseMap.h"
class Player;

class MapPlayerIcon :public BaseMap
{
public:
	MapPlayerIcon() { Init(); }
	~MapPlayerIcon()override {}

	void Update()override;
	void PostUpdate()override;
	void Init()override;
	void DrawSprite()override;

	void SetPlayer(const std::shared_ptr<Player> _player) { m_player = _player; }

private:

	std::weak_ptr<Player> m_player;

	Math::Vector3 m_scale;

};