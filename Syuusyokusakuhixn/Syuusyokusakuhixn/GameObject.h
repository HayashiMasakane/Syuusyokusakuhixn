#pragma once
#include<string>
#include"GameObjectId.h"

class ComponentManager;
/// <summary>
/// ゲームオブジェクトの基底クラス
/// ゲームオブジェクトマネージャでインスタンス化
/// </summary>
class GameObject
{
private:
	const GameObjectId m_gameObjectId;
	ComponentManager& m_componentManager;

public:
	GameObject(const GameObjectId& _gameObjectId, ComponentManager& _componentManager);	//	固有の名前を入れる
	virtual ~GameObject();

	virtual void Init() = 0;
	virtual void Uninit() = 0;
	virtual void Update() = 0;
	//	描画はシステムでする


	template<typename T>
	T* AddComponent();


};


#include"ComponentManager.h"
/// <summary>
/// コンポーネントを自身に追加
/// ComponentManagerのprivate:AddComponentにアクセス
/// </summary>
/// <typeparam name="T">つけたいコンポーネント</typeparam>
/// <returns>つけたTのポインタ</returns>
template<typename T>
T* GameObject::AddComponent()
{
	return m_componentManager.AddComponent<T>(m_gameObjectId);
}
