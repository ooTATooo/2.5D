#pragma once

#include "../BaseStage.h"

class BackGround:public BaseStage
{
public:

	BackGround() { Init(); }
	~BackGround()override {};

	void Init()override;
	void DrawUnLit()override;

private:

	std::shared_ptr<KdSquarePolygon> m_poly = nullptr;
};