#include "EnemyManager.h"

#include "../Object/Enemy/Enemy01/Enemy01.h"
#include "../Object/Enemy/Enemy02/Enemy02.h"
#include "../Object/Enemy/Enemy03/Enemy03.h"
#include "../Object/Map/MapEnemyPoint/MapEnemyPoint.h"

void EnemyManager::Init()
{
	Load("Asset/Data/EnemyManager.csv");
}

void EnemyManager::AddEnemy(SpawnType _type, KdGameObject::ObjType _enemyType, int _num)
{
	std::shared_ptr<Enemy01> enemy01 = std::make_shared<Enemy01>();
	std::shared_ptr<Enemy02> enemy02 = std::make_shared<Enemy02>();
	std::shared_ptr<Enemy03> enemy03 = std::make_shared<Enemy03>();
	std::shared_ptr<MapEnemyPoint> mapEnemyPoint = std::make_shared<MapEnemyPoint>();

	switch (_enemyType)
	{
	case KdGameObject::ObjType::Enemy01:
		for (auto& obj: SceneManager::Instance().GetObjList())
		{
			if (obj->GetObjType() == KdGameObject::ObjType::Player)
			{
				enemy01->SetPlayer(obj);

			}
			if (obj->GetObjType() == KdGameObject::ObjType::Monolith)
			{
				enemy01->SetBeacon(obj);
			}
		}
		enemy01->SetPos(m_spawnPosList[_type]);
		SceneManager::Instance().AddObject(enemy01);

		mapEnemyPoint->SetEnemy(enemy01);
		SceneManager::Instance().AddObject(mapEnemyPoint);

		break;
	case KdGameObject::ObjType::Enemy02:
		for (auto& obj : SceneManager::Instance().GetObjList())
		{
			if (obj->GetObjType() == KdGameObject::ObjType::Player)
			{
				enemy02->SetPlayer(obj);

			}
			if (obj->GetObjType() == KdGameObject::ObjType::Monolith)
			{
				enemy02->SetBeacon(obj);
			}
		}
		enemy02->SetPos(m_spawnPosList[_type]);
		SceneManager::Instance().AddObject(enemy02);

		mapEnemyPoint->SetEnemy(enemy02);
		SceneManager::Instance().AddObject(mapEnemyPoint);

		break;
	case KdGameObject::ObjType::Enemy03:
		for (auto& obj : SceneManager::Instance().GetObjList())
		{
			if (obj->GetObjType() == KdGameObject::ObjType::Player)
			{
				enemy03->SetPlayer(obj);

			}
			if (obj->GetObjType() == KdGameObject::ObjType::Monolith)
			{
				enemy03->SetBeacon(obj);
			}
		}
		enemy03->SetPos(m_spawnPosList[_type]);
		SceneManager::Instance().AddObject(enemy03);

		mapEnemyPoint->SetEnemy(enemy03);
		SceneManager::Instance().AddObject(mapEnemyPoint);

		break;
	}
}

void EnemyManager::Load(std::string a_filePath)
{
	std::ifstream ifs(a_filePath);
	if (!ifs.is_open()) { return; }

	std::vector<float> data;
	std::vector<Math::Vector3> pos;
	std::string str;

	while (getline(ifs, str))
	{
		std::istringstream iss(str);//ファイルから取ってきた文字列を操る
		std::string conmaString;//コンマ区切りになった変数を格納

		while (getline(iss, conmaString, ','))
		{
			float tempData = (float)stoi(conmaString);

			data.push_back(tempData);
		}
	}

	ifs.close();

	for (int i = 0; i < data.size(); i += 3)
	{
		pos.push_back({ data[i],data[i + 1],data[i + 2] });
	}

	m_spawnPosList[SpawnType::Top_Left] = pos[0];
	m_spawnPosList[SpawnType::Top_Center] = pos[1];
	m_spawnPosList[SpawnType::Top_Right] = pos[2];
	m_spawnPosList[SpawnType::Bottom_Left] = pos[3];
	m_spawnPosList[SpawnType::Bottom_Center] = pos[4];
	m_spawnPosList[SpawnType::Bottom_Right] = pos[5];
	m_spawnPosList[SpawnType::Left_Top] = pos[6];
	m_spawnPosList[SpawnType::Left_Center] = pos[7];
	m_spawnPosList[SpawnType::Left_Bottom] = pos[8];
	m_spawnPosList[SpawnType::Right_Top] = pos[9];
	m_spawnPosList[SpawnType::Right_Center] = pos[10];
	m_spawnPosList[SpawnType::Right_Bottom] = pos[11];
}
