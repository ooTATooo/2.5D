#pragma once

#include "../BaseStage.h"

class Ground :public BaseStage
{
public:

	Ground() { Init(); };
	~Ground()override {};

	void Init()override;
	void DrawLit()override;

private:

	std::shared_ptr<KdModelData> m_model;

};