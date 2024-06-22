#pragma once

#include "../BaseEnemy.h"

class Boss :public BaseEnemy
{
public:

	Boss() { Init(); }
	~Boss()override {}

	void Update()override;
	void PostUpdate()override;
	void Init()override;

private:

};