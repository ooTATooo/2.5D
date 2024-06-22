#pragma once

class TitleBaseStage :public KdGameObject
{
public:

	TitleBaseStage() { Init(); }
	~TitleBaseStage()override {}

	void PreUpdate()override {}
	void Init()override {}
	void GenerateDepthMapFromLight()override {}
	void DrawLit()override {}
	void DrawUnLit()override {}
	void DrawBright()override {}

protected:

	Math::Vector3 m_pos;
	
};