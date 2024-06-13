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
#include "../../Object/Enemy/Boss/Boss.h"
#include "../../Object/Monument/Monument.h"
#include "../../Object/HpBar/MonumentHp/MonumentHP.h"

void GameScene::Event()
{
	if (GetAsyncKeyState('T') & 0x8000)
	{
		SceneManager::Instance().SetNextScene
		(
			SceneManager::SceneType::Title
		);
	}

	if (!m_monumentHp.expired()) { m_monumentHp.lock()->SetPlayer(m_player); }

	CameraUpdate();
}

void GameScene::Init()
{
	// カメラ生成＆視野角設定
	m_camera = std::make_shared<KdCamera>();	//1 メモリ確保
	m_camera->SetProjectionMatrix(60);			//2	視野角設定

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
	player->SetCamera(m_camera);
	player->SetGround(ground);
	AddObject(player);
	m_player = player;

	//std::shared_ptr<Beacon> beacon = std::make_shared<Beacon>();
	//AddObject(beacon);

	std::shared_ptr<Monument> monument = std::make_shared<Monument>();
	AddObject(monument);

	std::shared_ptr<MonumentHp> monumentHp = std::make_shared<MonumentHp>();
	monumentHp->SetPos(monument->GetPos());
	monumentHp->SetCamera(m_camera);
	AddObject(monumentHp);
	m_monumentHp = monumentHp;

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

void GameScene::CameraUpdate()
{
	UINT scrollType = 0;

	Math::Vector3 playerPos;
	if (!m_player.expired())
	{
		playerPos = m_player.lock()->GetPos();
	}

	Math::Matrix rotMat = Math::Matrix::CreateRotationX(DirectX::XMConvertToRadians(45));

	Math::Matrix transMat = Math::Matrix::CreateTranslation(0, 8, -8);

	Math::Matrix pTransMat;

	Math::Matrix mat;
	mat = rotMat * transMat;

	// スクロールの限界処理
	if (playerPos.z > 27.0f) { scrollType |= ScrollType::Up; }
	if (playerPos.z < -27.0f) { scrollType |= ScrollType::Down; }
	if (playerPos.x < -26.0f) { scrollType |= ScrollType::Left; }
	if (playerPos.x > 26.0f) { scrollType |= ScrollType::Right; }

	if (scrollType & ScrollType::Up) { pTransMat = Math::Matrix::CreateTranslation(playerPos.x, playerPos.y, 27.0f); }
	if (scrollType & ScrollType::Down) { pTransMat = Math::Matrix::CreateTranslation(playerPos.x, playerPos.y, -27.0f); }
	if (scrollType & ScrollType::Left) { pTransMat = Math::Matrix::CreateTranslation(-26.0f, playerPos.y, playerPos.z); }
	if (scrollType & ScrollType::Right) { pTransMat = Math::Matrix::CreateTranslation(26.0f, playerPos.y, playerPos.z); }

	if (scrollType == (ScrollType::Up | ScrollType::Left)) { pTransMat = Math::Matrix::CreateTranslation(-26.0f, playerPos.y, 27.0f); }
	if (scrollType == (ScrollType::Up | ScrollType::Right)) { pTransMat = Math::Matrix::CreateTranslation(26.0f, playerPos.y, 27.0f); }
	if (scrollType == (ScrollType::Down | ScrollType::Left)) { pTransMat = Math::Matrix::CreateTranslation(-26.0f, playerPos.y, -27.0f); }
	if (scrollType == (ScrollType::Down | ScrollType::Right)) { pTransMat = Math::Matrix::CreateTranslation(26.0f, playerPos.y, -27.0f); }

	if (scrollType == 0) { pTransMat = Math::Matrix::CreateTranslation(playerPos); }

	mat *= pTransMat;

	// カメラに行列をセット
	// この時点では画面には反映されない
	m_camera->SetCameraMatrix(mat);
}