#include "GameScene.h"
#include "../SceneManager.h"
#include "../../ImGuiManager/ImGuiManager.h"

#include "../../Object/Player/Player.h"
#include "../../Object/Ground/Ground.h"
#include "../../Object/WallFawme/WallFrame.h"
#include "../../Object/Pillar/Pillar.h"
#include "../../Object/Enemy/Enemy01/Enemy01.h"
#include "../../Object/Enemy/Enemy02/Enemy02.h"
#include "../../Object/Enemy/Enemy03/Enemy03.h"
#include "../../Object/Boss/Boss.h"
#include "../../Object/Beacon/Beacon.h"
#include "../../Object/BeaconHp/BeaconHp.h"


void GameScene::Event()
{
	if (GetAsyncKeyState('T') & 0x8000)
	{
		SceneManager::Instance().SetNextScene
		(
			SceneManager::SceneType::Title
		);
	}

	Math::Vector3 playerPos;
	if (!m_player.expired())
	{
		playerPos = m_player.lock()->GetPos();
	}
	ImGuiManager::Instance().SetPlayerPos(playerPos);

	Math::Matrix rotMat = Math::Matrix::CreateRotationX(DirectX::XMConvertToRadians(45));

	Math::Matrix transMat = Math::Matrix::CreateTranslation(0, 8, -8);

	Math::Matrix pTransMat = Math::Matrix::CreateTranslation(playerPos);

	Math::Matrix mat;
	mat = rotMat * transMat * pTransMat;

	// カメラに行列をセット
	// この時点では画面には反映されない
	m_camera->SetCameraMatrix(mat);
}

void GameScene::Init()
{
	// カメラ生成＆視野角設定
	m_camera = std::make_unique<KdCamera>();	//1 メモリ確保
	m_camera->SetProjectionMatrix(60);			//2	視野角設定

	std::shared_ptr<Enemy01> enemy01 = std::make_shared<Enemy01>();
	AddObject(enemy01);

	std::shared_ptr<Enemy02> enemy02 = std::make_shared<Enemy02>();
	AddObject(enemy02);

	std::shared_ptr<Enemy03> enemy03 = std::make_shared<Enemy03>();
	AddObject(enemy03);

	std::shared_ptr<Boss> boss = std::make_shared<Boss>();
	AddObject(boss);

	std::shared_ptr<Player> player = std::make_shared<Player>();
	AddObject(player);
	m_player = player;

	std::shared_ptr<Ground> ground = std::make_shared<Ground>();
	AddObject(ground);

	std::shared_ptr<WallFrame> wall = std::make_shared<WallFrame>();
	AddObject(wall);

	static const int width = 4;
	static const int height = 4;
	float posX[width] = { -20.0f,-10.0f,10.0f,20.0f };
	float posZ[height] = { 20.0f,10.0f,-10.0f,-20.0f };

	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			std::shared_ptr<Pillar> pillar = std::make_shared<Pillar>();
			pillar->SetPos({ posX[i], 0, posZ[j]});
			AddObject(pillar);
		}
	}

	//std::shared_ptr<Beacon> beacon = std::make_shared<Beacon>();
	//AddObject(beacon);

	//std::shared_ptr<BeaconHp> beaconHp = std::make_shared<BeaconHp>();
	//AddObject(beaconHp);
}
