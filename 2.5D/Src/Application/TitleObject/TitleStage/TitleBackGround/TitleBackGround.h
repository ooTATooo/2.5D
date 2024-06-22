#pragma once

#include "../TitleBaseStage.h"

class TitleBackGround:public TitleBaseStage
{
public:

	TitleBackGround() { Init(); }
	~TitleBackGround()override {};

	void Init()override;
	void DrawUnLit()override;

private:

	std::shared_ptr<KdSquarePolygon> m_poly;
};