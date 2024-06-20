#include "GameScene.h"
#include "../SceneManager.h"
#include "../../ImGuiManager/ImGuiManager.h"

#include "../../EnemyManager/EnemyManager.h"
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
		//SceneManager::Instance().SetNextScene
		//(
		//	SceneManager::SceneType::Title
		//);
		if (!flg)
		{
			EnemyManager::Instance().AddEnemy(EnemyManager::SpawnType::Top_Center, KdGameObject::ObjType::Enemy01, 5);
			EnemyManager::Instance().AddEnemy(EnemyManager::SpawnType::Left_Center, KdGameObject::ObjType::Enemy02, 5);
			EnemyManager::Instance().AddEnemy(EnemyManager::SpawnType::Right_Center, KdGameObject::ObjType::Enemy03, 5);
			flg = true;
		}
	}
	else
	{
		flg = false;
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

	//std::shared_ptr<Boss> boss = std::make_shared<Boss>();
	//AddObject(boss);

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

	std::shared_ptr<MapPlayerIcon> mapPlayerIcon = std::make_shared<MapPlayerIcon>();
	mapPlayerIcon->SetPlayer(player);
	AddObject(mapPlayerIcon);

}
