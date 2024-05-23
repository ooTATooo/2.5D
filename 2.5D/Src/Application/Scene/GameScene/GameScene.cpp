#include "GameScene.h"
#include"../SceneManager.h"

#include "../../Object/Ground/Ground.h"
#include "../../Object/Player/Player.h"
#include "../../Object/Beacon/Beacon.h"
//#include "../../Object/BeaconHP/BeaconHP.h"

void GameScene::Event()
{
	// 拡縮行列
	Math::Matrix scaleMat = Math::Matrix::CreateScale(1, 1, 1);

	// 回転行列
	Math::Matrix rotMatX = Math::Matrix::CreateRotationX(DirectX::XMConvertToRadians(45));

	// 移動行列
	Math::Matrix transMat = Math::Matrix::CreateTranslation(0, 5, -5);

	Math::Matrix pTransMat = Math::Matrix::CreateTranslation(m_player->GetPos());

	// カメラのワールド行列を作成し、適応させる
	// 行列の親子関係
	Math::Matrix _mWorld = scaleMat * rotMatX * transMat *pTransMat;
	m_camera->SetCameraMatrix(_mWorld);
}

void GameScene::Init()
{
	m_camera = std::make_unique<KdCamera>();
	m_camera->SetProjectionMatrix(60);

	std::shared_ptr<Ground> ground = std::make_shared<Ground>();
	ground->Init();
	AddObject(ground);

	std::shared_ptr<Beacon> beacon = std::make_shared<Beacon>();
	beacon->Init();
	//m_beacon = beacon;
	AddObject(beacon);

	std::shared_ptr<Player> player = std::make_shared<Player>();
	player->Init();
	m_player = player;
	AddObject(player);

	//std::shared_ptr<BeaconHP> beaconHP = std::make_shared<BeaconHP>();
	////m_beaconHp = beaconHP;
	//AddObject(beaconHP);
}
