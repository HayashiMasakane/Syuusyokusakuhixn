#pragma once
#include "GameObject.h"
class TestObject : public GameObject
{
private:


public:
	TestObject(const GameObjectId m_gameObjectId);
	~TestObject()=default;

	 void Init()override;
	 void Uninit() override;
	 void Update()override;


};

