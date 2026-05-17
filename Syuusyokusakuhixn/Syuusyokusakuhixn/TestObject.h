#pragma once
#include "GameObject.h"

class ComponentManager;

class TestObject : public GameObject
{
private:


public:
	TestObject(GameObjectId _gameObjectId, ComponentManager& _componentManager);
	~TestObject() = default;

	void Init()override;
	void Uninit() override;
	void Update()override;


};

