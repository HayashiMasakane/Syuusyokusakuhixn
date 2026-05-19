#pragma once
#include<vector>
#include<unordered_map>
#include<typeindex>
#include"GameObjectId.h"

class Component;
class GameObject;

/// <summary>
/// コンポーネントの生成管理をする。Componentの更新はシステムでする
/// AddComponentはGameObjectクラスで使う
/// </summary>
class ComponentManager
{
private:
	//  フレンド宣言
	friend GameObject;  //  AddComponentを使用


	using ComponentId = std::type_index;
	using OwnerComponentMap = std::unordered_map<GameObjectId, std::vector<void*>>;


	// 型ごとに vector<T> を保持するための辞書
	//  type_index  :Component派生クラス
	//  void*       :vector<T>の先頭アドレスを入れる
	std::unordered_map<ComponentId, void*> m_componentMap;


	//	m_componentMapをO(1)にするための辞書
	std::unordered_map< ComponentId, OwnerComponentMap > m_ownerComponentMap;


	ComponentManager(ComponentManager&) = delete;
	ComponentManager operator=(ComponentManager&) = delete;

	// 型ごとに vector<T> を取得（なければ作る）
	template<typename T>
	std::vector<T>& GetMap();

	//	Componentを作成
	template<typename T>
	T* AddComponent(const GameObjectId& _objectId);


public:
	ComponentManager() = default;
	~ComponentManager();

	void Init();
	void Uninit();



	//	オブジェクトに引っ付いているのTコンポーネント群を取得
	template<typename T>
	std::vector<T*> GetComponents(const GameObjectId _objectId);

	//	Tコンポーネント群を取得
	template<typename T>
	std::vector<T>& GetAllComponents();


};



/// <summary>
/// 各ComponentMapの取得or生成
/// </summary>
/// <typeparam name="T">取得したい配列</typeparam>
/// <returns>配列</returns>
template<typename T>
std::vector<T>& ComponentManager::GetMap()
{
	auto key = std::type_index(typeid(T));

	// まだ配列がないなら作る
	if (m_componentMap.find(key) == m_componentMap.end())
	{
		m_componentMap[key] = new std::vector<T>();
	}

	return *static_cast<std::vector<T>*>(m_componentMap[key]);
}



#include<iostream>
/// <summary>
/// コンポーネントを追加（同じコンポーネントを複数個付けれるぞ）
/// ゲームオブジェクトクラス内で登録する
/// </summary>
/// <typeparam name="T">Component派生クラス</typeparam>
/// <param name="_objectId">つけたいオブジェクト</param>
/// <returns>つけたComponentのポインタ</returns>
template<typename T>
T* ComponentManager::AddComponent(const GameObjectId& _objectId)
{
	auto& arr = GetMap<T>();

	arr.push_back(T(_objectId));
	T* comp = &arr.back();

	//	辞書に登録
	m_ownerComponentMap[typeid(T)][_objectId].push_back(static_cast<void*>(comp));

	std::cout << "AddComponent::GameObjectId:" << _objectId << std::endl;
	return comp;
}

/// <summary>
///	オブジェクトIdに対応したTのコンポーネントポインタをすべて取得
/// </summary>
/// <typeparam name="T">取得したいComponent</typeparam>
/// <param name="_objectId">ゲームオブジェクトId</param>
/// <returns>Tのvector配列</returns>
template<typename T>
std::vector<T*> ComponentManager::GetComponents(const GameObjectId _objectId)
{
	std::vector<T*> result;

	auto typeKey = std::type_index(typeid(T));

	//	Tがないならはじく
	if (!m_ownerComponentMap.contains(typeKey))
	{
		return result;
	}


	auto& ownerMap = m_ownerComponentMap[typeKey];

	//	オブジェクトにTがないならはじく
	if (!ownerMap.contains(_objectId))
	{
		return result;
	}

	//	対応したコンポーネントを入れて戻り値にする
	for (void* p : ownerMap[_objectId])
	{
		result.push_back(static_cast<T*>(p));

	}

	return result;
}

template<typename T>
std::vector<T>& ComponentManager::GetAllComponents()
{
	return GetMap<T>();
}
