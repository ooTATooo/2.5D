#pragma once

#include "../CameraBase.h"

class TrackingCamera :public CameraBase
{
public:

	// スクロール限界
	enum ScrollType
	{
		Up = 1 << 0,
		Down = 1 << 1,
		Left = 1 << 2,
		Right = 1 << 3,
	};

	TrackingCamera() {}
	~TrackingCamera()override {}

	void Init()override;
	void Update()override;
};