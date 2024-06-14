#include "GameScene.h"
#include "../SceneManager.h"
#include "../../ImGuiManager/ImGuiManager.h"

#include "../../Object/Camera/Camera.h"
#include "../../Object/Player/Player.h"
#include "../../Object/Ground/Ground.h"
#include "../../Object/WallFawme/WallFrame.h"
#include "../../Object/Pillar/Pillar.h"
#include "../../Object/Enemy/Enemy01/Enemy01.h"
#include "../../Object/Enemy/Enemy02/Enemy02.h"
#include "../../Object/Enemy/Enemy03/Enemy03.h"
#include "../../Object/Enemy/Boss/Boss.h"
#include "../../Object/Monument/Monument.h"

void GameScene::Event()
{
	if (GetAsyncKeyState('T') & 0x8000)
	{
		SceneManager::Instance().SetNextScene
		(
			SceneManager::SceneType::Title
		);
	}

	//if (!m_monumentHp.expired()) { m_monumentHp.lock()->SetPlayer(m_player); }

}

void GameScene::Init()
{
	// カメラ生成＆視野角設定
	//m_camera = std::make_shared<KdCamera>();	//1 メモリ確保
	//m_camera->SetProjectionMatrix(60);			//2	視野角設定

	std::shared_ptr<Camera> camera = std::make_shared<Camera>();
	AddObject(camera);

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

	std::shared_ptr<Player> player = std::make_shared<Player>();
	camera->SetPlayer(player);
	//player->SetCamera(camera);
	player->SetGround(ground);
	AddObject(player);
	m_player = player;

	std::shared_ptr<Monument> monument = std::make_shared<Monument>();
	monument->SetCamera(camera);
	monument->SetPlayer(player);
	AddObject(monument);

	std::shared_ptr<Enemy01> enemy01 = std::make_shared<Enemy01>();
	enemy01->SetBeacon(monument);
	enemy01->SetPlayer(player);
	AddObject(enemy01);

	std::shared_ptr<Enemy02> enemy02 = std::make_shared<Enemy02>();
	enemy02->SetBeacon(monument);
	enemy02->SetPlayer(player);
	AddObject(enemy02);

	std::shared_ptr<Enemy03> enemy03 = std::make_shared<Enemy03>();
	enemy03->SetBeacon(monument);
	enemy03->SetPlayer(player);
	AddObject(enemy03);

	std::shared_ptr<Boss> boss = std::make_shared<Boss>();
	AddObject(boss);

}
