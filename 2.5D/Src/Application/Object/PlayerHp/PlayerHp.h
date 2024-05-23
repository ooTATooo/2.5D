#pragma once

class PlayerHp :public KdGameObject
{
public:

	PlayerHp() { Init(); }
	~PlayerHp()override {}

	void Update()override;
	void Init()override;
	void DrawSprite()override;

private:

	struct Data
	{
		KdTexture tex;
		Math::Matrix mat;
		Math::Vector3 pos;
	};

	Data m_backHp;
	Data m_yellowHp;
	Data m_greenHp;
};