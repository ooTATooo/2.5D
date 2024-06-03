#include "AssetManager.h"

void AssetManager::Animation()
{
}

void AssetManager::Init()
{
	LoadPolygon("Player", "Asset/Textures/Player/player.png");
	m_polyList["Player"]->SetSplit(9, 6);
	m_polyList["Player"]->SetPivot(KdSquarePolygon::PivotType::Center_Bottom);
}

void AssetManager::LoadTex(std::string _name, std::string _filePath)
{
	std::shared_ptr<KdTexture> tex = std::make_shared<KdTexture>();
	tex->Load(_filePath);
	m_texList[_name] = tex;
}

void AssetManager::LoadPolygon(std::string _name, std::string _filePath)
{
	std::shared_ptr<KdSquarePolygon> poly = std::make_shared<KdSquarePolygon>();
	poly->SetMaterial(_filePath);
	m_polyList[_name] = poly;
}

void AssetManager::LoadModel(std::string _name, std::string _filePath)
{
	std::shared_ptr<KdModelData> model = std::make_shared<KdModelData>();
	model->Load(_filePath);
	m_modelList[_name] = model;
}
