#include "GameScene.h"
#include "../SceneManager.h"
#include "../../ImGuiManager/ImGuiManager.h"

#include "../../EnemyManager/EnemyManager.h"
#include "../../GameObject/Camera/Camera.h"
#include "../../GameObject/Stage/BackGround/BackGround.h"
#include "../../GameObject/Stage/Ground/Ground.h"
#include "../../GameObject/Stage/WallFawme/WallFrame.h"
#include "../../GameObject/Stage/Pillar/Pillar.h"
#include "../../GameObject/Stage/Monolith/Monolith.h"
#include "../../GameObject/Player/Player.h"
#include "../../GameObject/Enemy/Boss/Boss.h"
#include "../../GameObject/HpBar/MonolithHp/MonolithHP.h"
#include "../../GameObject/Map/MapBackGround/MapBackGround.h"
#include "../../GameObject/Map/MapPlayerIcon/MapPlayerIcon.h"
#include "../../GameObject/Map/MapMonolithPoint/MapMonolithPoint.h"
#include "../../GameObject/Map/MapEnemyPoint/MapEnemyPoint.h"
#include "../../GameObject/UI/WaveTex/WaveTex.h"
#include "../../GameObject/UI/GameOver/GameOver.h"
#include "../../GameObject/UI/GameOverBack/GameOverBack.h"
#include "../../GameObject/UI/GameClear/GameClear.h"

void GameScene::Event()
{
	if (m_spawnNum > 0)
	{
		switch (m_wave)
		{
		case EnemyManager::WaveType::First:
			if (m_frame <= 0)
			{
				if (!m_flg)
				{
					std::shared_ptr<WaveTex> wave = std::make_shared<WaveTex>();
					wave->SetWave(m_wave);
					AddObject(wave);
					m_flg = true;
					m_frame = 180;
				}
				else
				{
					m_spawn = EnemyManager::Instance().GetSpawnType();
					EnemyManager::Instance().AddEnemy(m_spawn, KdGameObject::ObjType::Slime);
					m_frame = 180;
					m_spawnNum--;
					//if (m_spawnNum == 0)
					//{
					//	m_wave = EnemyManager::WaveType::Second;
					//	m_spawnNum = 7;
					//	m_flg = false;
					//}
				}
			}
			break;
		case EnemyManager::WaveType::Second:
			if (m_frame <= 0)
			{
				if (!m_flg)
				{
					std::shared_ptr<WaveTex> wave = std::make_shared<WaveTex>();
					wave->SetWave(m_wave);
					AddObject(wave);
					m_flg = true;
					m_frame = 180;
				}
				else
				{
					m_spawn = EnemyManager::Instance().GetSpawnType();
					m_objtype = EnemyManager::Instance().GetObjType(false);
					EnemyManager::Instance().AddEnemy(m_spawn, m_objtype);
					m_frame = 180;
					m_spawnNum--;

					//if (m_enemyCount == m_spawnNum)
					//{
					//	m_wave = EnemyManager::WaveType::Final;
					//	m_spawnNum = 6;
					//	m_flg = false;
					//}
				}
			}
			break;
		case EnemyManager::WaveType::Final:
			if (m_frame <= 0)
			{
				if (!m_flg)
				{
					std::shared_ptr<WaveTex> wave = std::make_shared<WaveTex>();
					wave->SetWave(m_wave);
					AddObject(wave);
					m_flg = true;
					m_frame = 180;
				}
				else
				{
					m_spawn = EnemyManager::Instance().GetSpawnType();
					m_objtype = EnemyManager::Instance().GetObjType(true);
					EnemyManager::Instance().AddEnemy(m_spawn, m_objtype);
					m_frame = 180;
					m_spawnNum--;

					//if (m_enemyCount == m_spawnNum)
					//{
					//	std::shared_ptr<GameClear> gameClear = std::make_shared<GameClear>();
					//	AddObject(gameClear);
					//	m_enemyCount = -1;
					//}
				}
			}
			break;
		}
	}

	if (GetAsyncKeyState('R') & 0x8000)
	{
		if (!flg[0])
		{
			m_wave = EnemyManager::WaveType::Second;
			m_spawnNum = 7;
			m_flg = false;
			flg[0] = true;
		}
	}
	else { flg[0] = false; }
	if (GetAsyncKeyState('T') & 0x8000)
	{
		if (!flg[1])
		{
			m_wave = EnemyManager::WaveType::Final;
			m_spawnNum = 6;
			m_flg = false;
			flg[1] = true;
		}
	}
	else{ flg[1] = false; }
	if (GetAsyncKeyState('F') & 0x8000)
	{
		if (!flg[2])
		{
			std::shared_ptr<GameClear> gameClear = std::make_shared<GameClear>();
			AddObject(gameClear);
			flg[2] = true;
		}
	}
	else{ flg[2] = false; }

	std::shared_ptr<Monolith> monolith = m_monolith.lock();
	if (monolith)
	{
		if (!monolith->GetAlive())
		{
			std::shared_ptr<GameOverBack> gameOverBack = std::make_shared<GameOverBack>();
			AddObject(gameOverBack);

			std::shared_ptr<GameOver> gameOver = std::make_shared<GameOver>();
			AddObject(gameOver);

			monolith->Expired();

			KdAudioManager::Instance().StopAllSound();
		}
	}

	m_frame--;
	if (m_frame <= 0) { m_frame = 0; }
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
			pillar->SetPos({ posX[i], 0, posZ[j] });
			AddObject(pillar);
		}
	}

	std::shared_ptr<Monolith> monolith = std::make_shared<Monolith>();
	AddObject(monolith);
	m_monolith = monolith;

	// 2D===========
	std::shared_ptr<MonolithHp> monumentHp = std::make_shared<MonolithHp>();
	monumentHp->SetPos(monolith->GetPos());
	monumentHp->SetCamera(camera);
	monumentHp->SetPlayer(player);
	monumentHp->SetMonolith(monolith);
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
