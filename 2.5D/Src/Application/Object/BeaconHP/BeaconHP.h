#pragma once

class BeaconHp :public KdGameObject
{
public:

	BeaconHp() { Init(); }
	~BeaconHp()override {}

	void Update()override;
	void Init()override;
	void DrawSprite()override;

	void SetCamera(std::weak_ptr<KdCamera> _camera) { m_camera = _camera; }

	//void SetPos(const Math::Vector3& pos)override { m_mWorld.Translation(pos); }
private:

	std::weak_ptr<KdCamera> m_camera;

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