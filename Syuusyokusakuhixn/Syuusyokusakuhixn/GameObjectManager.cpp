#include "GameObjectManager.h"
#include<Windows.h>
#include"GameObject.h"
/// <summary>
/// 削除されるときにUninit()を処理
/// </summary>
GameObjectManager::~GameObjectManager()
{
	Uninit();
}

/// <summary>
/// 初期化
/// </summary>
void GameObjectManager::Init()
{

}

/// <summary>
///	m_gameObjectsのすべての削除処理をする
/// </summary>
void GameObjectManager::Uninit()
{

}

/// <summary>
/// オブジェクト全てを更新
/// </summary>
void GameObjectManager::Update()
{

}

/// <summary>
/// オブジェクトを取得
/// </summary>
/// <param name="_name">取得したいオブジェクト名</param>
const GameObject* GameObjectManager::GetGameObject(std::string _name)
{
	//	引数と同じ名前がないならはじく
	if (!m_gameObjectDictionary.contains(_name))
	{
		MessageBoxA(NULL, "警告", "オブジェクトが登録されていません", MB_ICONWARNING | MB_OK);
		return nullptr;
	}

	return m_gameObjectDictionary.at(_name);
}

/// <summary>
/// オブジェクトの削除依頼をする
/// </summary>
/// <param name="_name">削除したいオブジェクト名</param>
void GameObjectManager::DeleteGameObject(std::string _name)
{
	// 名前が存在しないならはじく
	if (!m_gameObjectDictionary.contains(_name))
	{
		MessageBoxA(NULL, "警告", "オブジェクトが登録されていません", MB_ICONWARNING | MB_OK);
		return;
	}

	// 辞書からポインタを取得
	GameObject* obj = m_gameObjectDictionary[_name];

	//	m_gameObjectsから削除
	for (size_t num = 0; num < m_gameObjects.size(); num++)
	{
		if (m_gameObjects[num].get() == obj)
		{
			m_gameObjects[num].reset();
			m_releasedGameObjectNum.push_back(num);	// 再利用リストへ追加

			break;
		}
	}

	// 辞書から削除
	m_gameObjectDictionary.erase(_name);

}

