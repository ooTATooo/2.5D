#pragma once

class AssetManager
{
public:

	void CallTex(std::string _name) { m_texList[_name]; }

	void CallPolygon(std::string _name) { m_polyList[_name]; }

	void CallModel(std::string _name) { m_modelList[_name]; }

private:

	void Animation();
	void Init();

	std::unordered_map<std::string, std::shared_ptr<KdTexture>> m_texList;

	std::unordered_map<std::string, std::shared_ptr<KdSquarePolygon>> m_polyList;

	std::unordered_map<std::string, std::shared_ptr<KdModelData>> m_modelList;

	void LoadTex(std::string _name, std::string _filePath);

	void LoadPolygon(std::string _name, std::string _filePath);

	void LoadModel(std::string _name, std::string _filePath);

private:

	AssetManager() { Init(); }
	~AssetManager() {}

public:

	static AssetManager& Instance()
	{
		static AssetManager instance;
		return instance;
	}
};