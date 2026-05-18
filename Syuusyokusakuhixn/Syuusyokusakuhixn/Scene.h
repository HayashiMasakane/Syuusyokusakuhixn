#pragma once
#include"GameObjectManager.h"
#include"ComponentManager.h"
/// <summary>
///	sceneの基底クラス
/// sceneマネージャでインスタンスを作る
/// </summary>
class Scene
{
private:
	GameObjectManager m_gameObjectManager;
	ComponentManager m_componentManager;

public:
	Scene() = default;
	virtual	~Scene() {};

	virtual void Init() = 0;
	virtual void Uninit() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;



	template<typename T>
	GameObject* AddGameObject(std::string _name);

};


template<typename T>
GameObject* Scene::AddGameObject(std::string _name)
{
	m_gameObjectManager.AddGameObject<T>(_name,m_componentManager);
	return nullptr;
}
