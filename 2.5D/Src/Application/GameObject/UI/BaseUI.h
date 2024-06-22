#pragma once

class BaseUI :public KdGameObject
{
public:

	BaseUI() { Init(); }
	~BaseUI()override {}

	void Update() {};
	void Init()override;
	void DrawSprite()override;

protected:

	std::shared_ptr<KdTexture> m_tex;

	Math::Vector3 m_pos; 
};