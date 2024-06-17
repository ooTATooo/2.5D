#include "GameScene.h"
#include "../SceneManager.h"
#include "../../ImGuiManager/ImGuiManager.h"

#include "../../Object/Camera/Camera.h"
#include "../../Object/Stage/BackGround/BackGround.h"
#include "../../Object/Stage/Ground/Ground.h"
#include "../../Object/Stage/WallFawme/WallFrame.h"
#include "../../Object/Stage/Pillar/Pillar.h"
#include "../../Object/Stage/Monolith/Monolith.h"
#include "../../Object/Player/Player.h"
#include "../../Object/Enemy/Enemy01/Enemy01.h"
#include "../../Object/Enemy/Enemy02/Enemy02.h"
#include "../../Object/Enemy/Enemy03/Enemy03.h"
#include "../../Object/Enemy/Boss/Boss.h"
#include "../../Object/HpBar/MonolithHp/MonolithHP.h"
#include "../../Object/Map/MapBackGround/MapBackGround.h"
#include "../../Object/Map/MapPlayerIcon/MapPlayerIcon.h"
#include "../../Object/Map/MapMonolithPoint/MapMonolithPoint.h"
#include "../../Object/Map/MapEnemyPoint/MapEnemyPoint.h"

void GameScene::Event()
{
	if (GetAsyncKeyState('T') & 0x8000)
	{
		SceneManager::Instance().SetNextScene
		(
			SceneManager::SceneType::Title
		);
	}
}

void GameScene::Init()
{
	std::shared_ptr<Camera> camera = std::make_shared<Camera>();
	AddObject(camera);

	std::shared_ptr<BackGround> back = std::make_shared<BackGround>();
	AddObject(back);

	std::shared_ptr<Ground> ground = std::make_shared<Ground>();
	AddObject(ground);

	std::shared_ptr<Player> player = std::make_shared<Player>();
	camera->SetPlayer(player);
	player->SetCamera(camera);
	player->SetGround(ground);
	AddObject(player);

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

	std::shared_ptr<Monolith> monolith = std::make_shared<Monolith>();
	AddObject(monolith);

	std::shared_ptr<Boss> boss = std::make_shared<Boss>();
	AddObject(boss);

	// 2D===========
	std::shared_ptr<MonolithHp> monumentHp = std::make_shared<MonolithHp>();
	monumentHp->SetPos(monolith->GetPos());
	monumentHp->SetCamera(camera);
	monumentHp->SetPlayer(player);
	AddObject(monumentHp);

	std::shared_ptr<MapBackGround> mapBackGround = std::make_shared<MapBackGround>();
	AddObject(mapBackGround);

	std::shared_ptr<MapMonolithPoint> mapMonolithPoint = std::make_shared<MapMonolithPoint>();
	mapMonolithPoint->SetMomolith(monolith);
	AddObject(mapMonolithPoint);

	AddEnemy(player, monolith, EnemyType::Enemy01);
	AddEnemy(player, monolith, EnemyType::Enemy02);
	AddEnemy(player, monolith, EnemyType::Enemy03);

	std::shared_ptr<MapPlayerIcon> mapPlayerIcon = std::make_shared<MapPlayerIcon>();
	mapPlayerIcon->SetPlayer(player);
	AddObject(mapPlayerIcon);

}

void GameScene::AddEnemy(std::weak_ptr<Player> _player, std::weak_ptr<Monolith> _monolith, EnemyType _type)
{
	std::shared_ptr<Enemy01> enemy01 = std::make_shared<Enemy01>();
	std::shared_ptr<Enemy02> enemy02 = std::make_shared<Enemy02>();
	std::shared_ptr<Enemy03> enemy03 = std::make_shared<Enemy03>();
	std::shared_ptr<MapEnemyPoint> mapEnemyPoint = std::make_shared<MapEnemyPoint>();

	switch (_type)
	{
	case GameScene::EnemyType::Enemy01:
		enemy01->SetBeacon(_monolith);
		enemy01->SetPlayer(_player);
		AddObject(enemy01);

		mapEnemyPoint->SetEnemy(enemy01);
		AddObject(mapEnemyPoint);

		break;
	case GameScene::EnemyType::Enemy02:
		enemy02->SetBeacon(_monolith);
		enemy02->SetPlayer(_player);
		AddObject(enemy02);

		mapEnemyPoint->SetEnemy(enemy02);
		AddObject(mapEnemyPoint);

		break;
	case GameScene::EnemyType::Enemy03:
		enemy03->SetBeacon(_monolith);
		enemy03->SetPlayer(_player);
		AddObject(enemy03);

		mapEnemyPoint->SetEnemy(enemy03);
		AddObject(mapEnemyPoint);

		break;
	}
}

