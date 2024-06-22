#pragma once

#include "../TitleBaseStage.h"

class TitleGround :public TitleBaseStage
{
public:

	TitleGround() { Init(); };
	~TitleGround()override {};

	void Init()override;
	void DrawLit()override;

private:

	std::shared_ptr<KdModelData> m_model;

};