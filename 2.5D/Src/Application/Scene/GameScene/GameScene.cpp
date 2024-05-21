#include "GameScene.h"
#include"../SceneManager.h"

#include "../../Object/Map/Map.h"
#include "../../Object/PlayerHp/PlayerHp.h"
#include "../../Object/Player/Player.h"
#include "../../Object/Skeleton/Skeleton.h"
#include "../../Object/Beacon/Beacon.h"

void GameScene::Event()
{
	if (GetAsyncKeyState('T') & 0x8000)
	{
		SceneManager::Instance().SetNextScene
		(
			SceneManager::SceneType::Title
		);
	}

	// 拡縮行列
	Math::Matrix _mScale = Math::Matrix::CreateScale(1, 1, 1);

	// 回転行列
	static float ang = 0;
	//ang++;
	Math::Matrix _mRotationX = Math::Matrix::CreateRotationX(DirectX::XMConvertToRadians(30));
	Math::Matrix _mRotationY = Math::Matrix::CreateRotationY(DirectX::XMConvertToRadians(ang));

	// 移動行列
	Math::Matrix _mTrans = Math::Matrix::CreateTranslation(pos);

	// カメラのワールド行列を作成し、適応させる
	// 行列の親子関係
	Math::Matrix _mWorld = (_mScale * _mRotationX * _mTrans * _mRotationY);
	m_camera->SetCameraMatrix(_mWorld);
}

void GameScene::Init()
{
	m_camera = std::make_unique<KdCamera>();
	m_camera->SetProjectionMatrix(60);

	std::shared_ptr<Map> map = std::make_shared<Map>();
	map->Init();
	AddObject(map);

	std::shared_ptr<Beacon> beacon = std::make_shared<Beacon>();
	beacon->Init();
	AddObject(beacon);

	std::shared_ptr<Skeleton> skeleton = std::make_shared<Skeleton>();
	skeleton->Init();
	AddObject(skeleton);

	std::shared_ptr<Player> player = std::make_shared<Player>();
	player->Init();
	AddObject(player);

	std::shared_ptr<PlayerHp> playerHp = std::make_shared<PlayerHp>();
	playerHp->Init();
	AddObject(playerHp);
}
