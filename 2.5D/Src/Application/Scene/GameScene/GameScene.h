#pragma once

#include"../BaseScene/BaseScene.h"

class Player;
class BeaconHp;
class Enemy01;
class Enemy02;
class Enemy03;

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
	std::weak_ptr<Enemy01> m_enemy01;
	std::weak_ptr<Enemy02> m_enemy02;
	std::weak_ptr<Enemy03> m_enemy03;
};
