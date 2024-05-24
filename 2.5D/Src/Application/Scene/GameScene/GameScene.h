#pragma once

#include"../BaseScene/BaseScene.h"

class Player;
class Beacon;
class BeaconHp;

class GameScene : public BaseScene
{
public :

	GameScene() { Init(); }
	~GameScene() {}

private:

	void Event() override;
	void Init() override;

	std::weak_ptr<Player> m_player;

};
