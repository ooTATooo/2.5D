#pragma once

#include"../BaseScene/BaseScene.h"

class Player;
class BeaconHp;

class GameScene : public BaseScene
{
public :
	// スクロール限界
	enum ScrollType
	{
		Up		= 1 << 0,
		Down	= 1 << 1,
		Left	= 1 << 2,
		Right	= 1 << 3,
	};

	GameScene() { Init(); }
	~GameScene() {}

private:

	void Event() override;
	void Init() override;

	// カメラ処理
	void CameraUpdate();

	std::weak_ptr<Player> m_player;
	std::weak_ptr<BeaconHp> m_beaconHp;
};
