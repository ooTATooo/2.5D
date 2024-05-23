#pragma once

class BeaconHp :public KdGameObject
{
public:

	BeaconHp() { Init(); }
	~BeaconHp()override {}

	void Update()override;
	void Init()override;
	void DrawSprite()override;

private:

	struct Data
	{
		KdTexture tex;
		Math::Matrix scaleMat;
		Math::Matrix transMat;
		Math::Matrix mat;
	};

	Data m_backHp;
	Data m_yellowHp;
	Data m_greenHp;
};