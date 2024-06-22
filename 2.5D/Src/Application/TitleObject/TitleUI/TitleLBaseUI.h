#pragma once

class TitleBaseUI :public KdGameObject
{
public:

	TitleBaseUI() { Init(); }
	~TitleBaseUI()override {}

	void Update()override {}
	void Init()override;
	void DrawSprite()override;

protected:

	std::shared_ptr<KdTexture> m_tex;

	Math::Vector3 m_pos; 
};