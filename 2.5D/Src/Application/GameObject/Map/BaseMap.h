#pragma once

class BaseMap :public KdGameObject
{
public:

	BaseMap() { Init(); }
	~BaseMap()override {}

	void Update()override {}
	void PostUpdate()override {}
	void Init()override;
	void DrawSprite()override;

	// 3D座標を2D座標へ変換
	const Math::Vector3 Convert2D(const Math::Vector3 _pos);

protected:

	std::shared_ptr<KdTexture> m_tex;
	Math::Vector3 m_pos;
	Math::Vector3 m_moveVec;
	float m_scale;

	Math::Color m_color;
	Animation::Dir m_dir;


	static const int MinMap_X = -480;
	static const int MinMap_Y = 200;
};