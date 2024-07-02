#pragma once

#include "../BaseMap.h"
class BaseEnemy;

class MapEnemyPoint :public BaseMap
{
public:

	MapEnemyPoint() { Init(); }
	~MapEnemyPoint()override {}

	void Update()override;
	void PostUpdate()override;
	void Init()override;
	void DrawSprite()override;

	void SetEnemy(const std::shared_ptr<BaseEnemy> _enemy) { m_enemy = _enemy; }

private:

	std::weak_ptr<BaseEnemy> m_enemy;

	bool m_flg = false;
};