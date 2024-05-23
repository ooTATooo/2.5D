#pragma once

#include"../BaseScene/BaseScene.h"

class Player;

class GameScene : public BaseScene
{
public :

	GameScene() { Init(); }
	~GameScene() {}

private:

	void Event() override;
	void Init() override;

	std::shared_ptr<Player> m_player;

	Math::Vector3 pos = { 0, 5, -5 };
};
