#pragma once

#include"../BaseScene/BaseScene.h"

class Player;
class Beacon;
class BeaconHP;

class GameScene : public BaseScene
{
public :

	GameScene() { Init(); }
	~GameScene() {}

private:

	void Event() override;
	void Init() override;

	std::shared_ptr<Player> m_player;
	//std::shared_ptr<Beacon> m_beacon;
	//std::shared_ptr<BeaconHP> m_beaconHp;
};
