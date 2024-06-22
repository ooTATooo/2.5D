#pragma once

class BaseUI :public KdGameObject
{
public:

	BaseUI() { Init(); }
	~BaseUI()override {}

	void Update() {};
	void PostUpdate()override;
	void Init()override;
	void DrawSprite()override;

protected:

	std::shared_ptr<KdTexture> m_tex;

	Math::Vector3 m_pos; 
	float m_scale;

	Math::Rectangle m_rect;
	Math::Color m_color;

};