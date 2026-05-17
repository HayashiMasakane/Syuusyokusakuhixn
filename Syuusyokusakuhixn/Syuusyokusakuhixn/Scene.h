#pragma once
#include"GameObjectManager.h"
/// <summary>
///	sceneの基底クラス
/// sceneマネージャでインスタンスを作る
/// </summary>
class Scene
{
private:
	GameObjectManager m_gameObjectManager;


public:
	Scene() = default;
	virtual	~Scene() {};

	virtual void Init() = 0;
	virtual void Uninit() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;

	GameObjectManager& GetGameObjectManager();



};

