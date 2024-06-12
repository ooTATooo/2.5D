#pragma once

class BackGround:public KdGameObject
{
public:

	BackGround() { Init(); }
	~BackGround()override {};

	void Init()override;
	void DrawUnLit()override;

private:

	std::shared_ptr<KdSquarePolygon> m_poly = nullptr;
};