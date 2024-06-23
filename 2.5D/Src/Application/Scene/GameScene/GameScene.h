#pragma once

#include"../BaseScene/BaseScene.h"

#include "../../EnemyManager/EnemyManager.h"

class Monolith;

class GameScene : public BaseScene
{
public :

	GameScene() { Init(); }
	~GameScene() {}

private:

	void Event() override;
	void Init() override;

	std::weak_ptr<Monolith> m_monolith;

	EnemyManager::SpawnType m_spawn = EnemyManager::SpawnType::Top_Center;
	EnemyManager::WaveType m_wave = EnemyManager::WaveType::First;
	KdGameObject::ObjType m_objtype = KdGameObject::ObjType::None;
	int m_spawnNum = 10;
	int m_enemyCount = 0;
	int m_frame = 120;
	bool m_flg = false;

	//=======
	static const int num = 3;
	bool flg[num];
};
