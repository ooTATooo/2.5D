#pragma once

#include"../BaseScene/BaseScene.h"
class Player;
class Monolith;

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

	enum class EnemyType
	{
		Enemy01,
		Enemy02,
		Enemy03,
	};
	void AddEnemy(std::weak_ptr<Player> _player, std::weak_ptr<Monolith> _monolith, EnemyType _type);

};
