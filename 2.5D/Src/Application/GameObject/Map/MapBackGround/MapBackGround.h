#pragma once

#include "../BaseMap.h"

class MapBackGround:public BaseMap
{
public:

	MapBackGround() { Init(); }
	~MapBackGround()override {}

	void PostUpdate()override;
	void Init()override;
	void DrawSprite()override;

private:
};