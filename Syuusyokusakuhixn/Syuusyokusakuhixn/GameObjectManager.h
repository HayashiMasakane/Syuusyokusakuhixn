#pragma once
#include<vector>
#include<string>
#include<memory>
#include<unordered_map>
#include<Windows.h>
#include"GameObjectId.h"
#include"GameObject.h"
class GameObject;

/// <summary>
/// ゲームオブジェクトを管理するコピー禁止クラス
/// 派生シーンの中で使用
/// </summary>
class GameObjectManager
{
private:
	//	フレンド宣言
	friend GameObject;

	std::vector<std::unique_ptr<GameObject>> m_gameObjects;
	std::vector<GameObjectId> m_releasedGameObjectNum;
	
	//	オブジェクト検索用
	std::unordered_map < std::string, GameObject* > m_gameObjectDictionary;
	


	//	GameObjectManager(GameObjectManager&) = delete;
	//GameObjectManager operator=(GameObjectManager&) = delete;

public:
	GameObjectManager() = default;
	~GameObjectManager();

	void Init();
	void Uninit();
	void Update();

	template<typename T>
	GameObject* AddGameObject(std::string _name);
	const GameObject* GetGameObject(std::string _name);
	void DeleteGameObject(std::string _name);


};


#include"GameObject.h"

/// <summary>
/// ゲームオブジェクトを作成する
/// 引数のstringと生成したオブジェクトを紐づけることでGetObjectでも取得可能
/// </summary>
/// <typeparam name="T">GameObject派生クラス</typeparam>
/// <param name="_name">作成するオブジェクトにつける名前</param>
/// <returns>Gameobujectのconstポインタ</returns>
template<typename T>
GameObject* GameObjectManager::AddGameObject(std::string _name)
{
	//	すでに同じ名前があるならはじく
	if (m_gameObjectDictionary.contains(_name)) 
	{
		MessageBoxA(NULL, "警告", "すでに同じオブジェクト名があります", MB_ICONWARNING | MB_OK);
		return nullptr;
	}


	//	オブジェクトをm_gameObjectsに作成
	GameObjectId objectId;

	if (!m_releasedGameObjectNum.empty())
	{
		objectId = m_releasedGameObjectNum.back();
		m_releasedGameObjectNum.pop_back();
	}
	else
	{
		objectId = m_gameObjects.size();
		m_gameObjects.push_back(nullptr); // スロット確保
	}

	m_gameObjects[objectId] = std::make_unique<T>(objectId);


	//	オブジェクト検索用Mapに登録
	m_gameObjectDictionary[_name] = m_gameObjects[objectId].get();


	return m_gameObjects[objectId].get();
}
