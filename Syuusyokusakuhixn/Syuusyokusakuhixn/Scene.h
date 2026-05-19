#pragma once
#include<string>
#include"GameObjectManager.h"
#include"ComponentManager.h"
/// <summary>
///	sceneの基底クラス
/// sceneマネージャでインスタンスを作る
/// </summary>
class Scene
{
private:
	const std::string m_sceneName;
	GameObjectManager m_gameObjectManager;
	ComponentManager m_componentManager;

public:
	Scene(const std::string& _sceneName);
	virtual	~Scene();

	virtual void Init() = 0;
	virtual void Uninit() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;


	ComponentManager& GetComponentManager();

	template<typename T>
	GameObject* AddGameObject(std::string _name);

};


template<typename T>
GameObject* Scene::AddGameObject(std::string _name)
{
	m_gameObjectManager.AddGameObject<T>(_name,m_componentManager);
	return nullptr;
}
